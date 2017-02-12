/*
 * Copyright (C) 2014-2017 StormCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "SpellScript.h"
#include "MoveSplineInit.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "iron_docks.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_RIDE_VEHICLE_HARDCODED    = 46598,

    SPELL_BREAKUP_SOUND             = 164319,
    SPELL_SPAWN_ENFORCERS           = 167632,
    SPELL_DUMMY                     = 164320,

    SPELL_ENGINE_RAIL_ANIMATION     = 164550,
};

enum Events
{
    EVENT_RELEASE_ENFORCERS = 1,
    EVENT_DRIVE_AWAY,
    EVENT_LOAD_IN_ENFORCERS, // short delayed event to make sure that the bosses are mounted up
};

Position const EngineEscapePos = { -13474.71f, -1200.375f, 11.31948f}; // yeah, Blizz really uses that coordinates...

class at_iron_docks_gauntlet_2 : public AreaTriggerScript
{
public:
    at_iron_docks_gauntlet_2() : AreaTriggerScript("at_iron_docks_gauntlet_2") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*entered*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* koramar = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_KORAMAR)))
                koramar->AI()->DoAction(ACTION_GAUNTLET_2);
        return true;
    }
};

class at_iron_docks_gauntlet_3 : public AreaTriggerScript
{
public:
    at_iron_docks_gauntlet_3() : AreaTriggerScript("at_iron_docks_gauntlet_3") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*entered*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* skulloc = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_SKULLOC)))
                skulloc->AI()->DoAction(ACTION_BOMBARD_GAUNTLET);
        return true;
    }
};

class at_iron_docks_gauntlet_4 : public AreaTriggerScript
{
public:
    at_iron_docks_gauntlet_4() : AreaTriggerScript("at_iron_docks_gauntlet_4") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*entered*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* koramar = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_KORAMAR)))
                koramar->AI()->DoAction(ACTION_GAUNTLET_3);
        return true;
    }
};

class at_iron_docks_gauntlet_5 : public AreaTriggerScript
{
public:
    at_iron_docks_gauntlet_5() : AreaTriggerScript("at_iron_docks_gauntlet_5") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*entered*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* koramar = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_KORAMAR)))
                koramar->AI()->DoAction(ACTION_GAUNTLET_END);

        std::list<Creature*> units;
        GetCreatureListWithEntryInGrid(units, player, NPC_ENGINE, 200.0f);
        for (std::list<Creature*>::iterator itr = units.begin(); itr != units.end(); ++itr)
            if ((*itr)->GetPositionZ() < 40.0f)
                (*itr)->AI()->DoAction(ACTION_RELEASE_ENFORCERS);

        return true;
    }
};

class at_iron_docks_oshir_intro : public AreaTriggerScript
{
public:
    at_iron_docks_oshir_intro() : AreaTriggerScript("at_iron_docks_oshir_intro") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*entered*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* koramar = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_KORAMAR)))
                koramar->AI()->DoAction(ACTION_OSHIR_INTRO);
        return true;
    }
};

class npc_iron_docks_engine : public CreatureScript
{
public:
    npc_iron_docks_engine() : CreatureScript("npc_iron_docks_engine") { }

    struct npc_iron_docks_engineAI : public ScriptedAI
    {
        npc_iron_docks_engineAI(Creature* creature) : ScriptedAI(creature)
        {
            _released = false;
            _mounted = false;
        }

        bool _released;
        bool _mounted;

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_RELEASE_ENFORCERS:
                    if (!_released)
                    {
                        events.ScheduleEvent(EVENT_RELEASE_ENFORCERS, 7000);
                        _released = true;
                    }
                    break;
                default:
                    break;
            }
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                if (Creature* wagon = who->ToCreature())
                {
                    wagon->SetDisplayId(wagon->GetCreatureTemplate()->Modelid2);
                    
                    // let's spawn the passengers by using a script since there is nothing like "vehicle_template_accessory_accessory"
                    if (wagon->GetEntry() == NPC_FLATBED)
                    {
                        if (Creature* ogron = me->SummonCreature(NPC_OGRON_LABORER_TRAIN, wagon->GetPosition(), TEMPSUMMON_DEAD_DESPAWN))
                        {
                            ogron->EnterVehicle(wagon, 0);
                            ogron->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SIT_GROUND);
                        }

                        if (Creature* flameslinger = me->SummonCreature(NPC_FLAMESLINGER_TRAIN, wagon->GetPosition(), TEMPSUMMON_DEAD_DESPAWN))
                            flameslinger->EnterVehicle(wagon, 1);

                        if (Creature* packbeast = me->SummonCreature(NPC_IRONHOOF_PACKBEASR_TRAIN, wagon->GetPosition(), TEMPSUMMON_DEAD_DESPAWN))
                            packbeast->EnterVehicle(wagon, 7);

                        if (me->GetPositionZ() < 40.0f) // make sure that we select the lower train since there is a cosmetic train on the upper rails
                            if (!_mounted)
                            {
                                events.ScheduleEvent(EVENT_LOAD_IN_ENFORCERS, 200);
                                _mounted = true;
                            }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RELEASE_ENFORCERS:
                        if (Unit* transport = me->GetVehicleKit()->GetPassenger(3))
                        {
                            // me->SendPlaySpellVisualKit(0, 48592);
                            DoCast(me, SPELL_ENGINE_RAIL_ANIMATION, true);
                            transport->CastSpell(transport, SPELL_BREAKUP_SOUND, true);
                            transport->CastSpell(transport, SPELL_SPAWN_ENFORCERS, true);
                            events.ScheduleEvent(EVENT_DRIVE_AWAY, 11000);
                            if (Unit* transport = me->GetVehicleKit()->GetPassenger(3))
                            {
                                if (Creature* neesa = transport->GetVehicleKit()->GetPassenger(0)->ToCreature())
                                    neesa->AI()->DoAction(ACTION_RELEASE_ENFORCERS);

                                if (Creature* makogg = transport->GetVehicleKit()->GetPassenger(1)->ToCreature())
                                    makogg->AI()->DoAction(ACTION_RELEASE_ENFORCERS);

                                if (Creature* ahriok = transport->GetVehicleKit()->GetPassenger(2)->ToCreature())
                                    ahriok->AI()->DoAction(ACTION_RELEASE_ENFORCERS);
                            }
                        }
                        break;
                    case EVENT_DRIVE_AWAY:
                        me->GetMotionMaster()->MovePoint(0, EngineEscapePos, false);
                        me->DespawnOrUnsummon(35000);
                        break;
                    case EVENT_LOAD_IN_ENFORCERS:
                        if (Unit* transport = me->GetVehicleKit()->GetPassenger(3))
                        {
                            if (Creature* neesa = me->FindNearestCreature(BOSS_NEESA_NOX, 100.0f, true))
                                neesa->EnterVehicle(transport, 0);

                            if (Creature* makogg = me->FindNearestCreature(BOSS_MAKOGG_EMBERBLADE, 100.0f, true))
                                makogg->EnterVehicle(transport, 1);

                            if (Creature* ahriok = me->FindNearestCreature(BOSS_AHRIOK_DUGRU, 100.0f, true))
                                ahriok->EnterVehicle(transport, 2);
                        }
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_iron_docks_engineAI(creature);
    }
};

void AddSC_iron_docks()
{
    new at_iron_docks_gauntlet_2();
    new at_iron_docks_gauntlet_3();
    new at_iron_docks_gauntlet_4();
    new at_iron_docks_gauntlet_5();
    new at_iron_docks_oshir_intro();
    new npc_iron_docks_engine();
}
