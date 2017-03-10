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

enum Spells
{
    SPELL_SHIELD_DAMAGE = 153480,
    SPELL_SHIELD_OBJECT = 153002,
    // SPELL_LINES_LEFT = 163559 
    // SPELL_LINES_RIGHT= 165064
    SPELL_AOE = 153006,
    SPELL_JUMP = 71809 // for start
};

enum Events
{
    EVENT_SHIELD_DMG = 1,
    EVENT_SHIELD_OBJ = 2,
    EVENT_AOE_PHASE = 3,
    EVENT_BACK = 4
};

Position const startpoint = { 1911.47f, 3183.50f, 30.79f, 0.85f };
class boss_kaathar : public CreatureScript
{
public:
    boss_kaathar() : CreatureScript("boss_kaathar") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_kaatharAI>(creature);
    }

    struct boss_kaatharAI : public BossAI
    {
        boss_kaatharAI(Creature* creature) : BossAI(creature, BOSS_KAATHAR)
        {
            Initialize();
            Reset();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            SetEquipmentSlots(false, 114923, 114923, 0);
        }

        void Initialize()
        {
            Holly_Barier(false);
        }
        bool check;
        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            DoZoneInCombat();
            Holly_Barier(true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_SHIELD_OBJ, 25000);
        }

        void Reset() override
        {
            _Reset();
            Initialize();
        }
        
        void Holly_Barier(bool state)
        {
            switch (state)
            {
            case false:
                if (GameObject* gameobject = ObjectAccessor::GetGameObject(*me, Holly_bar))
                    gameobject->Delete();
                break;
            case true:
                if (GameObject*  gameobject = me->SummonGameObject(OBJECT_Holly_barier, 1911.47f, 3183.50f, 30.79f, 0.85f, 0, 0, 0, 0, 0))
                    Holly_bar = gameobject->GetGUID();
                break;
            }
        }

        void MovementInform (uint32 type, uint32 id) override
        {
            if (id == 1)
            {
                me->StopMoving();
                DoCastAOE(SPELL_AOE);
                events.ScheduleEvent(EVENT_BACK, 10000);
            }
        }
        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SetBossState(BOSS_KAATHAR, DONE);
            Holly_Barier(false);
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
                case EVENT_SHIELD_DMG:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_SHIELD_DAMAGE);
                    events.ScheduleEvent(EVENT_SHIELD_OBJ, 25000);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(1, startpoint);
                    me->AttackStop();
                    break;
                case EVENT_SHIELD_OBJ:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_SHIELD_OBJECT);
                    events.ScheduleEvent(EVENT_SHIELD_DMG, 1000);
                    break;
                case EVENT_BACK:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        ObjectGuid crystalguid;
        ObjectGuid Holly_bar;
    };
};
class crystal_trigger : public CreatureScript
{
public:
    crystal_trigger() : CreatureScript("crystal_trigger") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<crystal_triggerAI>(creature);
    }

    struct crystal_triggerAI : public ScriptedAI
    {
        crystal_triggerAI(Creature* creature) : ScriptedAI(creature)
        {    
        }
        EventMap events;

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
        }
    };
};

enum Spells_of_Niami
{
    SPELL_STASIS_OF_VOID = 154840,
    SPELL_LIGHT = 166933
};

enum Events_of_Niami
{
    EVENT_DOOR_OPEN = 10,
    EVENT_COUNTINUE = 11,
    EVENT_STASIS = 12,
    EVENT_WENT=13,
    EVENT_PROCESS=14
};

enum Yells
{
    SAY_HELLO_01 = 0,
    SAY_HELLO_02 = 1,
    SAY_TALKWITH = 2,
    SAY_QUESTION = 3,
    SAY_LETS = 4,
    SAY_DESCRIBE = 5
};
class npc_tuulani : public CreatureScript
{
public:
    npc_tuulani() : CreatureScript("npc_tuulani") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_tuulaniAI>(creature);
    }
    struct npc_tuulaniAI : public ScriptedAI
    {
        npc_tuulaniAI(Creature* creature) : ScriptedAI(creature)
        {
            _count = 0;
            _check = false;
            _st = false;
        }
        EventMap events;
        uint32 _count;
        bool _check;
        bool _st;
        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;
            switch (id)
            {
            case 2:
                _count++;
                Talk(SAY_TALKWITH);
                break;
            case 3:
                if (!_st)
                {
                    me->StopMoving();
                    Talk(SAY_QUESTION);
                    events.ScheduleEvent(EVENT_DOOR_OPEN, 1000);
                    _st = true;
                }
                break;
            case 6:
                _count++;
                Talk(SAY_DESCRIBE);
                break;
            case 10:
                me->StopMoving();
                DoCast(me, SPELL_STASIS_OF_VOID);
                me->setActive(false);
                break;
            default:
                _count++;
                break;
            }
        }
        void UpdateAI(uint32 diff) override
        {

            if (!_check)
                if (Unit* nearPlayer = me->SelectNearestPlayer(10.0f))
                {
                    Talk(SAY_HELLO_01);
                    events.ScheduleEvent(EVENT_WENT, 8000);
                    events.ScheduleEvent(EVENT_PROCESS, 15000);
                    _check = true;
                }
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DOOR_OPEN:
                    DoCastAOE(SPELL_LIGHT);
                    events.ScheduleEvent(EVENT_COUNTINUE, 5500);
                    break;
                case EVENT_COUNTINUE:
                    Talk(SAY_LETS);
                    if (GameObject* gm = me->FindNearestGameObject(OBJECT_Holly_barier_Wall, 20.0f))
                        gm->UseDoorOrButton(0, false, me);
                    _count++;
                    break;
                case EVENT_WENT:
                    Talk(SAY_HELLO_02);
                    break;
                case EVENT_PROCESS:
                    me->GetMotionMaster()->MovePoint(_count, Niami_waypoints[_count]);
                    events.ScheduleEvent(EVENT_PROCESS,3500);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        ObjectGuid holyshield;
    };
};
void AddSC_boss_kaathar()
{
    new boss_kaathar();
    new crystal_trigger();
    new npc_tuulani();
}
