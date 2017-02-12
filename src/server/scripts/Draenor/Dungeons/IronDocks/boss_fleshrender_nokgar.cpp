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

#include "iron_docks.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Vehicle.h"

enum Spells
{
    // Nok'Gar

    // Dreadfang

    // Grom'Kar Flameslinger
    SPELL_BURNING_ARROWS        = 164234,
    SPELL_BURNING_ARROWS_AURA   = 164632,
};

enum Events
{
    EVENT_DISMOUNT = 1,
    EVENT_BURNING_ARROWS,
};

enum Actions
{
    ACTION_DREADFANG_DISMOUNTED = 1,
    ACTION_DREADFANG_DIED,
};

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_ARROW_BARRAGE       = 2,
    SAY_BURNING_ARROWS      = 3,
    SAY_PROVOCATION         = 4,
    SAY_ANOUNCE_PROVOCATION = 5,
    SAY_DEATH               = 6,
    SAY_DREADFANG_DEAD      = 7,
};

enum Areatriggers
{
    AT_BURNING_ARROWS = 2596,
};

class boss_fleshrender_nokgar : public CreatureScript
{
public:
    boss_fleshrender_nokgar() : CreatureScript("boss_fleshrender_nokgar") { }

    struct boss_fleshrender_nokgarAI : public BossAI
    {
        boss_fleshrender_nokgarAI(Creature* creature) : BossAI(creature, DATA_FLESHRENDER_NOKGAR)
        {
            dreadfang = nullptr;
        }

        Creature* dreadfang;

        void Reset() override
        {
            _Reset();
            if (dreadfang = me->SummonCreature(BOSS_DREADFANG, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN))
                me->EnterVehicle(dreadfang, 0);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
            events.ScheduleEvent(EVENT_BURNING_ARROWS, 16000);
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SendBossKillCredit(CREDIT_FLESHRENDER_NOKGAR);

            if (Creature* koramar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KORAMAR)))
                koramar->AI()->DoAction(ACTION_GAUNTLET_1);

            if (dreadfang && dreadfang->IsAlive())
                dreadfang->KillSelf();

            _JustDied();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (dreadfang)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, dreadfang);

            me->GetMotionMaster()->MoveTargetedHome();
            summons.DespawnAll();
            _EnterEvadeMode();
            _DespawnAtEvade();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_DREADFANG_DISMOUNTED:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    events.CancelEvent(EVENT_DISMOUNT);
                    dreadfang = nullptr;
                    break;
                case ACTION_DREADFANG_DIED:
                    Talk(SAY_DREADFANG_DEAD);
                    break;
                default:
                    break;
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BURNING_ARROWS:
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<boss_fleshrender_nokgarAI>(creature);
    }
};

class boss_dreadfang : public CreatureScript
{
public:
    boss_dreadfang() : CreatureScript("boss_dreadfang") { }

    struct boss_dreadfangAI : public ScriptedAI
    {
        boss_dreadfangAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript())
        {
            _dismounted = false;
        }

        EventMap events;
        InstanceScript* instance;
        bool _dismounted;

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (Creature* nokgar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FLESHRENDER_NOKGAR)))
                nokgar->AI()->EnterEvadeMode();
        }

        void JustDied(Unit* killer) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (Creature* nokgar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FLESHRENDER_NOKGAR)))
                nokgar->AI()->DoAction(ACTION_DREADFANG_DISMOUNTED);
            if (killer->GetEntry() != me->GetEntry())
                if (Creature* nokgar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FLESHRENDER_NOKGAR)))
                    nokgar->AI()->DoAction(ACTION_DREADFANG_DIED);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->GetHealthPct() <= 50.0f && !_dismounted)
            {
                if (Creature* nokgar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FLESHRENDER_NOKGAR)))
                    nokgar->AI()->DoAction(ACTION_DREADFANG_DISMOUNTED);
                _dismounted = true;
            }
        }

        void DoAction(int32 action) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetIronDocksAI<boss_dreadfangAI>(creature);
    }
};

void AddSC_boss_fleshrender_nokgar()
{
    new boss_fleshrender_nokgar();
    new boss_dreadfang();
}
