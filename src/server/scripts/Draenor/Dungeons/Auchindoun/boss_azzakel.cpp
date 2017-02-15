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
#include "Auchindoun.h"

enum spells
{
    SPELL_FEAL_LASH = 153234,
    SPELL_CURTAIN_OF_FLAME = 153396,
    SPELL_ARGUS = 153764
};

enum npc
{
    NPC_FIREMAN = 79510,
    NPC_BLAZING_ROGUE = 79511,
    NPC_FELGUARDIAN = 76259,
    NPC_AZZAKEL_TRIGGER = 100102
};

enum spells_of_npc
{
    SPELL_FEL_DETONATE = 167092,
    SPELL_IGNITION = 154018,
    SPELL_FEL_TREAD = 157173
};

enum events
{
    EVENT_FEAL_LASH = 1,
    EVENT_CURTAIN_OF_FLAME = 2,
    EVENT_FLYPHASE = 3,
    EVENT_BACK = 4,
    EVENT_FEL_POOl = 5
};

enum points
{
    POINT_AIR = 0,
    POINT_GROUND = 1
};
Position const Flypost = { 1949.93f, 2721.15f, 56.16f, 0.0f };
Position const Landpost = { 1926.27f, 2723.02f, 30.79f, 0.0f };
#define count 3
Position const Summ_pos [count] = 
{
    {1907.84f,2749.25f,30.80f,4.6f},
    {1883.98f,2726.08f,30.79f,6.15f},
    {1905.36f,2699.54f,30.79f,1.43f}
};
class boss_azakel : public CreatureScript
{
public:
    boss_azakel() : CreatureScript("boss_azakel") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_azakelAI>(creature);
    }

    struct boss_azakelAI : public BossAI
    {
        boss_azakelAI(Creature* creature) : BossAI(creature, BOSS_AZAKEL)
        {
            me->SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, float(400));
            me->UpdateAttackPowerAndDamage();
        }

        void Reset() override
        {
            _Reset();
            Initialize();
        }

        void Initialize()
        {
            DemonicPortal(false);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            DemonicPortal(true);
            _MainActions();
        }

        void _summon()
        {
            me->SummonCreature(NPC_FELGUARDIAN,Summ_pos[0],TEMPSUMMON_CORPSE_DESPAWN,0);
            me->SummonCreature(NPC_FIREMAN, Summ_pos[1], TEMPSUMMON_CORPSE_DESPAWN, 0);
            me->SummonCreature(NPC_BLAZING_ROGUE, Summ_pos[2], TEMPSUMMON_CORPSE_DESPAWN, 0);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            switch (id)
            {
            case POINT_AIR:
                events.ScheduleEvent(EVENT_BACK, 9500);
                DoCastAOE(SPELL_ARGUS);
                _summon();
                break;
            case POINT_GROUND:
                events.Reset();
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                _MainActions();
                events.ScheduleEvent(EVENT_FEL_POOl, 1000);
                break;
            default:
                break;
            }
        }
        void _MainActions()
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_FEAL_LASH, 2000);
            events.ScheduleEvent(EVENT_CURTAIN_OF_FLAME, 4000);
            events.ScheduleEvent(EVENT_FLYPHASE, 30000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            DemonicPortal(false);
        }

        void DemonicPortal(bool state)
        {
            switch (state)
            {
            case true:
                if (GameObject*  gameobject = me->SummonGameObject(OBJECT_Fel_barier, 1911.64f, 2722.51f, 31.57f, 3.14f, 0, 0, 0, 0, 0))
                    FelBarier = gameobject->GetGUID();
                if (GameObject*  gameobject = me->SummonGameObject(OBJECT_DemonicPortal, 1911.64f, 2722.51f, 31.57f, 3.14f, 0, 0, 0, 0, 0))
                    DemonPortal = gameobject->GetGUID();
                break;
            case false:
                if (GameObject* gameobject = ObjectAccessor::GetGameObject(*me, FelBarier))
                    gameobject->Delete();
                if (GameObject* gameobject = ObjectAccessor::GetGameObject(*me, DemonPortal))
                    gameobject->Delete();
                break;
            }
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
                case EVENT_FEAL_LASH:
                    DoCast(SelectTarget(SELECT_TARGET_TOPAGGRO), SPELL_FEAL_LASH);
                    events.ScheduleEvent(EVENT_FEAL_LASH, 6000);
                    break;
                case EVENT_CURTAIN_OF_FLAME:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_CURTAIN_OF_FLAME);
                    events.ScheduleEvent(EVENT_CURTAIN_OF_FLAME, 8000);
                    break;
                case EVENT_FLYPHASE:
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->GetMotionMaster()->MovePoint(POINT_AIR,Flypost);
                    break;
                case EVENT_BACK:
                    me->GetMotionMaster()->MovePoint(POINT_GROUND, Landpost);
                    break;
                case EVENT_FEL_POOl:
                    for (uint32 i = 0; i < 2; i++)
                        if (Unit* player = me->SelectNearestPlayer(50.0f))
                            me->SummonCreature(NPC_AZZAKEL_TRIGGER, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 0);
                    events.ScheduleEvent(EVENT_FEL_POOl, 10000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private: 
        ObjectGuid DemonPortal;
        ObjectGuid FelBarier;
    };
};

enum spells_dummy
{
    SPELL_TRIGGER = 183142,
    SPELL_AURA = 153726
};

class Azzakel_trigger : public CreatureScript
{
public:
    Azzakel_trigger() : CreatureScript("Azzakel_trigger") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<Azzakel_triggerAI>(creature);
    }

    struct Azzakel_triggerAI : public ScriptedAI
    {
        Azzakel_triggerAI(Creature* creature) : ScriptedAI(creature)
        {

        }
        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            DoCast(me, SPELL_TRIGGER);
            me->DespawnOrUnsummon(15000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            if (Unit* nearPlayer = me->SelectNearestPlayer(3.0f))
                if (!nearPlayer->HasAura(SPELL_AURA))
                    nearPlayer->AddAura(SPELL_AURA, nearPlayer);
            if (Unit* nearPlayer = me->SelectNearestPlayer(6.0f))
                if (nearPlayer->GetDistance2d(me) > 3)
                    nearPlayer->RemoveAura(SPELL_AURA);
        }
    };
};

void AddSC_boss_azakel()
{
    new boss_azakel();
    new Azzakel_trigger();

}
