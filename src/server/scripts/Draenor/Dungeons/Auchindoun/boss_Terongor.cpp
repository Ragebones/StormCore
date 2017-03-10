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
    SPELL_SUMMON_ABISSAL = 140762, // first phase
    SPELL_SHADOWBOLT = 156829,
    SPELL_CORUPT = 156842,
    SPELL_FIRE_RAIN = 156974, // spell doesn`t work
    SPELL_DRAIN = 156854, // end first phase
    SPELL_SEED_OF_ANGER = 156921, // affliction
    SPELL_EXHAUSTION = 164841,
    SPELL_AGONY = 156925,
    SPELL_UNSTABLE_AFFLICTION = 156954, // end affliction
    SPELL_CHAOS_BOLT = 164846, // destruction
    SPELL_IMMOLATE = 156964,
    SPELL_IGNITION = 156960,
    SPELL_INCINIRATE = 156963,
    SPELL_FAIR_RAIN_DESTRUCTION = 156974, // end destruction
    SPELL_DEMONIC_LEAP = 157041, // demonologic
    SPELL_ROCK = 156965,
    SPELL_WAVE_OF_CHAOS = 157001,
    SPELL_TOUCH_OF_CHAOS = 156968,
    SPELL_CORUPT_DEMON = 156842, // end demonologic
    SPELL_JUMP = 71809,
    SPELL_IMUNE = 177763
};

enum Models
{
    Destruction = 21254,
    Affliction = 16263,
    Demono = 64429,
    Terongor=54036
};

enum events
{
    EVENT_SUMMON_ABISSAL = 1, // first phase
    EVENT_SHADOWBOLT = 2,
    EVENT_CORUPT = 3,
    EVENT_FIRE_RAIN = 4,
    EVENT_DRAIN = 5, // end first phase
    EVENT_EXHAUSTION = 6, // affliction
    EVENT_SEED_OF_ANGER=7,
    EVENT_AGONY = 8,
    EVENT_UNSTABLE_AFFLICTION = 9, // end affliction
    EVENT_CHAOS_BOLT = 10, // destruction
    EVENT_IMMOLATE = 11,
    EVENT_IGNITION = 12,
    EVENT_INCINIRATE = 13, // end destruction
    EVENT_DEMONIC_LEAP = 14, // demonologic
    EVENT_ROCK = 15,
    EVENT_WAVE_OF_CHAOS = 16,
    EVENT_TOUCH_OF_CHAOS = 17,
    EVENT_CORUPT_DEMON = 18, // end demonologic
    EVENT_END=19
};
Position at_end = { 1885.49f, 2996.36f, 17.30f, 1.74f };
class boss_teron : public CreatureScript
{
public:
    boss_teron() : CreatureScript("boss_teron") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_teronAI>(creature);
    }

    struct boss_teronAI : public BossAI
    {
        boss_teronAI(Creature* creature) : BossAI(creature, BOSS_TERON)
        {
            Initialize();
        }

        void Reset() override
        {
            _Reset();
            Initialize();
        }

        void Initialize()
        {
            check = false;
            check_end = false;
            me->SetDisplayId(Terongor);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
        bool check;
        bool check_end;
        Unit* player;

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            me->RemoveAllAuras();
            _StartPhase();
        }

        void _StartPhase()
        {
            events.ScheduleEvent(EVENT_SHADOWBOLT,5500);
            events.ScheduleEvent(EVENT_CORUPT, 5000);
            events.ScheduleEvent(EVENT_SUMMON_ABISSAL, 10000);
            events.ScheduleEvent(EVENT_DRAIN, 15000);
            events.ScheduleEvent(EVENT_FIRE_RAIN, 3500);
        }

        void _Endphase()
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->AttackStop();
            events.Reset();
            DoCast(me, SPELL_IMUNE, true);
            me->GetMotionMaster()->MovePoint(1, at_end);
        }

        void _MainPhase(uint32 rnd)
        {
            switch (rnd)
            {
            case 0:
                me->SetDisplayId(Affliction);
                events.ScheduleEvent(EVENT_SHADOWBOLT,2000);
                events.ScheduleEvent(EVENT_AGONY, 5000);
                events.ScheduleEvent(EVENT_SEED_OF_ANGER,4500);
                events.ScheduleEvent(EVENT_EXHAUSTION, 8000);
                events.ScheduleEvent(EVENT_DRAIN, 15000);
                events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, 6700);
                break;
            case 1:
                me->SetDisplayId(Destruction);
                events.ScheduleEvent(EVENT_CHAOS_BOLT, 10000);
                events.ScheduleEvent(EVENT_INCINIRATE, 2000);
                events.ScheduleEvent(EVENT_IMMOLATE, 5000);
                events.ScheduleEvent(EVENT_FIRE_RAIN, 3500);
                break;
            case 2:
                me->SetDisplayId(Demono);
                events.ScheduleEvent(EVENT_DEMONIC_LEAP, 1500);
                events.ScheduleEvent(EVENT_SHADOWBOLT, 2000);
                events.ScheduleEvent(EVENT_CORUPT, 5000);
                events.ScheduleEvent(EVENT_ROCK, 8000);
                events.ScheduleEvent(EVENT_TOUCH_OF_CHAOS, 9000);
                break;
            default:
                break;
            }
        }

        void JustReachedHome() override
        {
            Reset();
            _JustReachedHome();
        }
        void JustSummoned(Creature* summon)
        {
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (id == 1)
            {
                DoCastAOE(SPELL_JUMP);
                events.ScheduleEvent(EVENT_END,1000);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SetBossState(BOSS_NIAMI, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;
            if ((me->GetHealthPct() <= 75) && (!check))
            {
                events.Reset();
                _MainPhase(rand() % 3);
                check = true;
            }
            if ((me->GetHealthPct() <= 10) && (!check_end))
            {
                check_end = true;
                _Endphase();
            }
            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SHADOWBOLT:
                    DoCast(SelectTarget(SELECT_TARGET_TOPAGGRO), SPELL_SHADOWBOLT);
                    events.ScheduleEvent(EVENT_SHADOWBOLT, 5500);
                    break;
                case EVENT_CORUPT:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_CORUPT);
                    events.ScheduleEvent(EVENT_CORUPT, 5000);
                    break;
                case EVENT_FIRE_RAIN:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_FIRE_RAIN);
                    events.ScheduleEvent(EVENT_FIRE_RAIN, 7500);
                    break;
                case EVENT_SUMMON_ABISSAL:
                    DoCastAOE(SPELL_SUMMON_ABISSAL);
                    break;
                case EVENT_DRAIN:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_DRAIN);
                    events.ScheduleEvent(EVENT_DRAIN, 15000);
                    break;
                case EVENT_AGONY:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_AGONY);
                    events.ScheduleEvent(EVENT_AGONY, 5000);
                    break;
                case EVENT_EXHAUSTION:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_EXHAUSTION);
                    events.ScheduleEvent(EVENT_EXHAUSTION, 8000);
                    break;
                case EVENT_UNSTABLE_AFFLICTION:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_UNSTABLE_AFFLICTION);
                    events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, 6700);
                    break;
                case EVENT_CHAOS_BOLT:
                    DoCast(SelectTarget(SELECT_TARGET_TOPAGGRO), SPELL_CHAOS_BOLT);
                    events.ScheduleEvent(EVENT_CHAOS_BOLT, 10000);
                    break;
                case EVENT_INCINIRATE:
                    DoCast(SelectTarget(SELECT_TARGET_TOPAGGRO), SPELL_INCINIRATE);
                    events.ScheduleEvent(EVENT_INCINIRATE, 5500);
                    break;
                case EVENT_IMMOLATE:
                    player = SelectTarget(SELECT_TARGET_RANDOM);
                    DoCast(player, SPELL_IMMOLATE);
                    events.ScheduleEvent(EVENT_IMMOLATE, 5000);
                    events.ScheduleEvent(EVENT_IGNITION, 3000);
                    break;
                case EVENT_IGNITION:
                    if (player->HasAura(SPELL_IMMOLATE))
                        DoCast(player, SPELL_IGNITION);
                    break;
                case EVENT_DEMONIC_LEAP:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_DEMONIC_LEAP);
                    events.ScheduleEvent(EVENT_DEMONIC_LEAP, 20000);
                    break;
                case EVENT_ROCK:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_ROCK);
                    events.ScheduleEvent(EVENT_ROCK, 8000);
                    break;
                case EVENT_SEED_OF_ANGER:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_SEED_OF_ANGER);
                    events.ScheduleEvent(EVENT_SEED_OF_ANGER, urand(19000,21000));
                    break;
                case EVENT_TOUCH_OF_CHAOS:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_TOUCH_OF_CHAOS);
                    events.ScheduleEvent(EVENT_TOUCH_OF_CHAOS, 9000);
                    break;
                case EVENT_END:
                    me->DespawnOrUnsummon(1000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};
void AddSC_boss_teron()
{
    new boss_teron();
}
