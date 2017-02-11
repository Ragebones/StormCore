/*
* Copyright (C) 2014-2017 StormCore
* 
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "Player.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"

enum GilneasSpells
{
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_01           = 59073,
    SPELL_GENERIC_QUEST_INVISIBILITY_DETECTION_1 = 49416,
    SPELL_UPDATE_PHASE_SHIFT                     = 82238
};

enum GilneasQuests
{
    QUEST_LOCKDOWN   = 14078
};

enum GilneasCityGuardGate
{
    EVENT_GUARD_TALK    = 1,
    EVENT_CITIZEN_TALK  = 2,

    GUARD_RANDOM_TEXT   = 1,
    CITIZEN_RANDOM_TEXT = 1
};

// Gilneas City Guard 34864 - phase 1
class npc_gilneas_city_guard_gate : public CreatureScript
{
    public:
        npc_gilneas_city_guard_gate() : CreatureScript("npc_gilneas_city_guard_gate") { }

        struct npc_gilneas_city_guard_gateAI : public ScriptedAI
        {
            npc_gilneas_city_guard_gateAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                events.Reset();

                if (me->GetMountID())
                    events.ScheduleEvent(EVENT_GUARD_TALK, urand(10000, 20000));
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                {
                    events.Update(diff);

                    if (uint32 pl_eventId = events.ExecuteEvent())
                    {
                        switch (pl_eventId)
                        {
                            case EVENT_GUARD_TALK:
                                Talk(GUARD_RANDOM_TEXT);
                                events.ScheduleEvent(EVENT_CITIZEN_TALK, urand(10000, 20000));
                                break;
                            case EVENT_CITIZEN_TALK:
                                {
                                    std::list<Creature*> pl_citizens;
                                    me->GetCreatureListWithEntryInGrid(pl_citizens, 44086, 35.0f);

                                    if (!pl_citizens.empty())
                                        if (Creature* pl_citizen = Trinity::Containers::SelectRandomContainerElement(pl_citizens))
                                            if (pl_citizen->IsAIEnabled)
                                                pl_citizen->AI()->Talk(CITIZEN_RANDOM_TEXT);

                                    events.ScheduleEvent(EVENT_GUARD_TALK, urand(20000, 40000));
                                }
                                break;
                            default:
                                break;
                        }
                    }

                    return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_gilneas_city_guard_gateAI (creature);
        }
};

enum PanickedCitizenGate
{
    EVENT_RANDOM_EMOTE  = 1
};

// Panicked Citizen 44086 - phase 1
class npc_panicked_citizen_gate : public CreatureScript
{
    public:
        npc_panicked_citizen_gate() : CreatureScript("npc_panicked_citizen_gate") { }

        struct npc_panicked_citizen_gateAI : public ScriptedAI
        {
            npc_panicked_citizen_gateAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_RANDOM_EMOTE, urand(4000, 8000));
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                {
                    events.Update(diff);

                    if (events.ExecuteEvent() == EVENT_RANDOM_EMOTE)
                    {
                        const uint16 pl_PanickedCitizenRandomEmote[5] =
                        {
                            EMOTE_ONESHOT_COWER,
                            EMOTE_ONESHOT_TALK,
                            EMOTE_ONESHOT_CRY,
                            EMOTE_ONESHOT_BEG,
                            EMOTE_ONESHOT_EXCLAMATION,
                        };

                        uint8 roll = urand(0, 4);
                        me->HandleEmoteCommand(pl_PanickedCitizenRandomEmote[roll]);
                        events.ScheduleEvent(EVENT_RANDOM_EMOTE, urand(2000, 5000));
                    }

                    return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_panicked_citizen_gateAI (creature);
        }
};

enum PrinceLiamGreymanePhase1
{
    NPC_PANICKED_CITIZEN         = 34851,
    CITIZEN_SAY_WHAT_AT_THE_ROOF = 1,

    EVENT_SAY_INTRO_1            = 1,
    EVENT_SAY_INTRO_2            = 2,
    EVENT_SAY_INTRO_3            = 3,

    LIAM_TALK_INTRO_1            = 1,
    LIAM_TALK_INTRO_2            = 2,
    LIAM_TALK_INTRO_3            = 3
};

// Prince Liam Greymane 34850 - phase 1
class npc_prince_liam_greymane_phase1 : public CreatureScript
{
    public:
        npc_prince_liam_greymane_phase1() : CreatureScript("npc_prince_liam_greymane_phase1") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_LOCKDOWN)
                if (Creature* pl_cinizen = creature->FindNearestCreature(NPC_PANICKED_CITIZEN, 30.0f))
                    if (pl_cinizen->IsAIEnabled)
                        pl_cinizen->AI()->Talk(CITIZEN_SAY_WHAT_AT_THE_ROOF);

            return false;
        }

        struct npc_prince_liam_greymane_phase1AI : public ScriptedAI
        {
            npc_prince_liam_greymane_phase1AI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_SAY_INTRO_1, 1000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                {
                    events.Update(diff);

                    if (uint32 pl_eventId = events.ExecuteEvent())
                    {
                        switch (pl_eventId)
                        {
                            case EVENT_SAY_INTRO_1:
                                Talk(LIAM_TALK_INTRO_1);
                                events.ScheduleEvent(EVENT_SAY_INTRO_2, 21000);
                                break;
                            case EVENT_SAY_INTRO_2:
                                Talk(LIAM_TALK_INTRO_2);
                                events.ScheduleEvent(EVENT_SAY_INTRO_3, 20000);
                                break;
                            case EVENT_SAY_INTRO_3:
                                Talk(LIAM_TALK_INTRO_3);
                                events.ScheduleEvent(EVENT_SAY_INTRO_1, 22000);
                                break;
                        }
                    }

                    return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_prince_liam_greymane_phase1AI (creature);
        }
};

// update player phase 1 to phase 2
class npc_lieutenant_walden : public CreatureScript
{
    public:
        npc_lieutenant_walden() : CreatureScript("npc_lieutenant_walden") { }

    private:
        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) override
        {
            if (quest->GetQuestId() == QUEST_LOCKDOWN)
            {
                player->CastSpell(player, SPELL_PHASE_QUEST_ZONE_SPECIFIC_01, false);
                player->CastSpell(player, SPELL_GENERIC_QUEST_INVISIBILITY_DETECTION_1, false);
                player->CastSpell(player, SPELL_UPDATE_PHASE_SHIFT, false);
                player->SaveToDB();
            }
            return false;

        }
};

void AddSC_gilneas()
{
   new npc_gilneas_city_guard_gate();
   new npc_panicked_citizen_gate();
   new npc_prince_liam_greymane_phase1();
   new npc_lieutenant_walden();
}
