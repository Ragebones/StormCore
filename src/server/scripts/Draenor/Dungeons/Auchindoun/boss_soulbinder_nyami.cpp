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
    SPELL_SHADOWW_WORD_PAIN = 154477,
    SPELL_MIND_PENETRATION = 154415,
    SPELL_TORTURED_SOULS = 174328, // only visual
    SPELL_SOUL_STORE_TRIGGER = 177549,
    SPELL_AURA = 177550, // aura in zone
    SPELL_SOUL_STORE_DMG = 154187,
    SPELL_SOUL_STORE_VISUAL_CAST = 155327,
};

enum Events
{
    EVENT_SHADOW_WORD = 1,
    EVENT_MIND_PEN = 2,
    EVENT_TORTURED_SOULS = 3,
    EVENT_SUMMON_SOULS = 4,
    EVENT_BACK = 5,
    EVENT_SOUL_STORE_VISUAL = 6,
    EVENT_TRIGGER_CHECK_RANGE = 7,
    EVENT_TRIGGER_CHECK_EFFECT = 8,
    EVENT_SOUL_STORE_REALY = 9,
    EVENT_SOUL_STORE_CREATE_TRIGGER = 10
};
class boss_niami : public CreatureScript
{
public:
    boss_niami() : CreatureScript("boss_niami") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_niamiAI>(creature);
    }

    struct boss_niamiAI : public BossAI
    {
        boss_niamiAI(Creature* creature) : BossAI(creature, BOSS_NIAMI)
        {
            me->setFaction(35);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetDisplayId(11686);
            Reset();
        }

        void Reset() override
        {
            _Reset();
            Initialize();
        }

        void Initialize()
        {
            check = false;
            k = 0;
        }
        bool check;
        uint32 k;

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            _Phase();
        }

        void _Phase()
        {
            events.ScheduleEvent(EVENT_SHADOW_WORD, 1000);
            events.ScheduleEvent(EVENT_MIND_PEN, 3000);
            events.ScheduleEvent(EVENT_SOUL_STORE_VISUAL,25000);
            if (check)
                events.ScheduleEvent(EVENT_TORTURED_SOULS, 10000);
        }
        void JustReachedHome() override
        {
            Reset();
            _JustReachedHome();
        }
        void JustSummoned(Creature* summon)
        {
            switch (summon->GetEntry())
            {
            case NPC_TRIGGER_NIAMI:
                summons.Summon(summon);
                summon->setActive(true);
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SetBossState(BOSS_NIAMI, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;
            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SHADOW_WORD:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_SHADOWW_WORD_PAIN);
                    events.ScheduleEvent(EVENT_SHADOW_WORD,8000);
                    break;
                case EVENT_MIND_PEN:
                    DoCast(SelectTarget(SELECT_TARGET_TOPAGGRO), SPELL_MIND_PENETRATION);
                    events.ScheduleEvent(EVENT_MIND_PEN, 10000);
                    break;
                case EVENT_SOUL_STORE_VISUAL:
                    DoCastAOE(SPELL_SOUL_STORE_VISUAL_CAST);
                    events.ScheduleEvent(EVENT_SOUL_STORE_REALY, 6000);
                    me->SummonCreature(NPC_TRIGGER_NIAMI, trigger_pos, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
                case EVENT_SOUL_STORE_REALY: 
                    while (k != 3)
                    {
                        DoCastAOE(SPELL_SOUL_STORE_DMG);
                        k++;
                    }
                    events.ScheduleEvent(EVENT_BACK, 6000);
                    break;
                case EVENT_BACK:
                    events.Reset();
                    check = true;
                    _Phase();
                    Initialize();
                    break;
                case EVENT_TORTURED_SOULS:
                    DoCastAOE(SPELL_TORTURED_SOULS);
                    events.ScheduleEvent(EVENT_SUMMON_SOULS, 3000);
                    break;
                case EVENT_SUMMON_SOULS:
                    me->SummonCreature(NPC_ARBITER, trigger_pos, TEMPSUMMON_CORPSE_DESPAWN, 0);
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class aura_trigger : public CreatureScript
{
public:
    aura_trigger() : CreatureScript("aura_trigger") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<aura_triggerAI>(creature);
    }
    struct aura_triggerAI : public ScriptedAI
    {
        aura_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
        }
        EventMap events;
        bool ch;

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_SOUL_STORE_CREATE_TRIGGER, 4000);
            events.ScheduleEvent(EVENT_TRIGGER_CHECK_EFFECT, 13000);
            events.ScheduleEvent(EVENT_TRIGGER_CHECK_RANGE, 2000);
            ch = false;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SOUL_STORE_CREATE_TRIGGER:
                    DoCast(me, SPELL_SOUL_STORE_TRIGGER, true);
                    break;
                case EVENT_TRIGGER_CHECK_EFFECT:
                    ch = true;
                    for (uint32 i = 0; i < 100; i++)
                        if (Unit* nearPlayer = me->SelectNearestPlayer(20.0f))
                            if (nearPlayer->HasAura(SPELL_AURA))
                                nearPlayer->RemoveAura(SPELL_AURA);
                    me->DespawnOrUnsummon(15000);
                    break;
                case EVENT_TRIGGER_CHECK_RANGE:
                    if (!ch)
                    {
                        if (Unit* nearPlayer = me->SelectNearestPlayer(3.0f))
                            if (!nearPlayer->HasAura(SPELL_AURA))
                                nearPlayer->AddAura(SPELL_AURA, nearPlayer);
                        events.ScheduleEvent(EVENT_TRIGGER_CHECK_RANGE, 2000);
                    }
                    break;
                default:
                    break;
                }
            }
        }
    };
};

enum spells_of_npc
{
    SPELL_HOJ = 154218,
    SPELL_HOLLY_RAGE = 154261
};

enum events_of_npc
{
    EVENT_HOJ = 11,
    EVENT_RAGE = 12
};
class npc_arbiter : public CreatureScript
{
public:
    npc_arbiter() : CreatureScript("npc_arbiter") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_arbiterAI>(creature);
    }
    struct npc_arbiterAI : public ScriptedAI
    {
        npc_arbiterAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
        }
        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_RAGE, 1000);
            events.ScheduleEvent(EVENT_HOJ, 2500);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RAGE:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_HOLLY_RAGE);
                    events.ScheduleEvent(EVENT_RAGE, 7000);
                    break;
                case EVENT_HOJ:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_HOJ);
                    events.ScheduleEvent(EVENT_RAGE, 8500);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};
void AddSC_boss_niami()
{
    new boss_niami();
    new aura_trigger();
    new npc_arbiter();
}
