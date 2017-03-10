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

#include "bloodmaul_slag_mines.h"
#include "GridNotifiers.h"
#include "Player.h"

enum eCreatures
{
	MOB_CAPTURED_MINER_HOSTILE = 74357,
	MOB_CAPTURED_MINER_FRIENDLY = 83725,
	NPC_EARTH_CRUSH_STALKER = 83650,
};

enum eSpells
{
	/// Slave Watcher Crushto
	// Earth Crush
	SPELL_EARTH_CRUSH = 153679, // Many spells with the same name, why is that ? TARGET_UNIT_CASTER_ENEMY_CONE
	SPELL_EARTH_CRUSH_SUMMON_STALKER = 153735, // Summon the giant rock (I think)

	// Ferocious Yell / Weakened Will
	SPELL_FEROCIOUS_YELL = 150759, // Many effects, trigger 150811
	SPELL_WEAKENED_WILL = 150811, // Force target to flee upon reaching 3 stacks
	SPELL_SHATTERED_WILL = 150813, // Flee spell related to Weakened Will

	// Wild Slam / Crushing Leap
	SPELL_WILD_SLAM = 150753, // Jumps to a target right after
	SPELL_CRUSHING_LEAP_SELECTOR = 150745, // Select a target + dummy on it
	SPELL_CRUSHING_LEAP_JUMP = 150746, // Jump to a target
	SPELL_CRUSHING_LEAP_FIXATE = 150818, // Periodically trigger 151270 with a base value (aggro amount ?)
	SPELL_CRUSHING_LEAP_AGGRO = 151270, // Add aggro to miners (dummy)
	SPELL_CRUSHING_LEAP_CONTROL = 152176, // Visual of being controlled ?
	// Crushing Leap doesn't seem to do something special, it just applies an aura forcing the miners to focus on this target

	// Raise the miners
	SPELL_RAISE_THE_MINERS = 150801, // Summon the npcs via triggered spell in dummy
	SPELL_RAISE_THE_MINERS_ALLIANCE = 150779, // Alliance version
	SPELL_RAISE_THE_MINERS_HORDE = 150775, // Horde version
	SPELL_RAISE_THE_MINERS_BOTH = 150780, // Hostile to both

	/// Captured Miners
	// Traumatic Strike
	SPELL_TRAUMATIC_STRIKE_PLAYERS = 150807, // Used during player phase
	SPELL_TRAUMATIC_STRIKE_BOSS = 151092, // Used when miners turn against the boss
};

enum eEvents
{
	/// Slave Watcher Crushto
	EVENT_EARTH_CRUSH = 1,
	EVENT_FEROCIOUS_YELL = 2,
	EVENT_WILD_SLAM = 3,
	EVENT_CRUSHING_LEAP = 4,
	EVENT_RAISE_THE_MINERS = 5,

	/// Captured Miners
	EVENT_CHECK_FACTION = 6, // Roll a chance to become friendly
	EVENT_TRAUMATIC_STRIKE = 7,
};

enum eTalks
{
	// TODO
};

class boss_slave_watcher_crushto : public CreatureScript
{
public:
	boss_slave_watcher_crushto() : CreatureScript("boss_slave_watcher_crushto")
	{

	}

	class boss_slave_watcher_crushto_AI : public ScriptedAI
	{
	public:
		boss_slave_watcher_crushto_AI(Creature* creature) :
			ScriptedAI(creature), m_instance(creature->GetInstanceScript())
		{
			m_events.Reset();
		}

		void Reset()
		{
			m_events.Reset();
			m_instance->SetBossState(DATA_CRUSHTO, NOT_STARTED);

			CleanArea();
		}

		void EnterCombat(Unit *target)
		{
			DoZoneInCombat();

			m_events.ScheduleEvent(EVENT_EARTH_CRUSH, 10 * IN_MILLISECONDS);
			m_events.ScheduleEvent(EVENT_FEROCIOUS_YELL, 7 * IN_MILLISECONDS);
			m_events.ScheduleEvent(EVENT_WILD_SLAM, 15 * IN_MILLISECONDS);
			m_events.ScheduleEvent(EVENT_RAISE_THE_MINERS, 20 * IN_MILLISECONDS);

			m_instance->SetBossState(DATA_CRUSHTO, IN_PROGRESS);
		}

		void UpdateAI(uint32 diff)
		{
			if (!UpdateVictim())
				return;

			m_events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = m_events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_EARTH_CRUSH:
					DoCast(me, SPELL_EARTH_CRUSH_SUMMON_STALKER);
					DoCastAOE(SPELL_EARTH_CRUSH);
					m_events.ScheduleEvent(EVENT_EARTH_CRUSH, urand(10, 20) * IN_MILLISECONDS);
					break;

				case EVENT_FEROCIOUS_YELL:
					DoCastAOE(SPELL_FEROCIOUS_YELL);
					m_events.ScheduleEvent(EVENT_FEROCIOUS_YELL, urand(12, 18) * IN_MILLISECONDS);
					break;

				case EVENT_WILD_SLAM:
					DoCastAOE(SPELL_WILD_SLAM);
					// Add a five second delay to not execute an event while jumping
					m_events.DelayEvents(5 * IN_MILLISECONDS);
					m_events.ScheduleEvent(EVENT_CRUSHING_LEAP, 1 * IN_MILLISECONDS);
					break;

				case EVENT_CRUSHING_LEAP:
					DoCastAOE(SPELL_CRUSHING_LEAP_SELECTOR);
					m_events.ScheduleEvent(EVENT_WILD_SLAM, urand(20, 25) * IN_MILLISECONDS);
					break;

				case EVENT_RAISE_THE_MINERS:
					DoCast(me, SPELL_RAISE_THE_MINERS);
					m_events.ScheduleEvent(EVENT_RAISE_THE_MINERS, urand(12, 18) * IN_MILLISECONDS);
					break;

				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

		void JustDied(Unit *killer)
		{
			m_instance->SetBossState(DATA_CRUSHTO, DONE);

			CleanArea();
		}

		void MovementInform(uint32 motionType, uint32 motionPoint)
		{
			/* Upon landing after Crushing Leap, force the miners to attack the targets
			* so apply the needed auras on the players. */
			if (motionType == EFFECT_MOTION_TYPE && motionPoint == EVENT_JUMP)
			{
				std::list<Player*> closests;
				me->GetPlayerListInGrid(closests, 10.0f);

				for (Player* player : closests)
					player->CastSpell(player, SPELL_CRUSHING_LEAP_FIXATE, true);
			}
		}

	private:
		EventMap        m_events;
		InstanceScript* m_instance;

		inline void CleanArea() const
		{

		}

		void RemoveCreaturesByEntry(uint32 entry) const
		{
			std::list<Creature*> creatures;
			me->GetCreatureListWithEntryInGrid(creatures, entry, 500.0f);

			for (Creature* creature : creatures)
				creature->DisappearAndDie();
		}
	};

	CreatureAI* GetAI(Creature *creature) const
	{
		return GetBloodmaulSlagAI<boss_slave_watcher_crushto_AI, Creature>(creature);
	}
};

class mob_captured_miner : public CreatureScript
{
public:
	mob_captured_miner() : CreatureScript("mob_captured_miner")
	{

	}

	class mob_captured_miner_AI : public ScriptedAI
	{
	public:
		mob_captured_miner_AI(Creature* creature) :
			ScriptedAI(creature), m_instance(creature->GetInstanceScript())
		{
			m_events.Reset();
		}

		enum eFactions
		{
			FACTION_HOSTILE = 14,
			FACTION_FRIENDLY = 35,
		};

		void Reset()
		{
			m_events.Reset();
			if (me->getFaction() == FACTION_HOSTILE)
				m_events.ScheduleEvent(EVENT_CHECK_FACTION, 10 * IN_MILLISECONDS);
		}

		void EnterCombat(Unit *target)
		{
			m_events.ScheduleEvent(EVENT_TRAUMATIC_STRIKE, 10 * IN_MILLISECONDS);
		}

		void UpdateAI(uint32 diff)
		{
			if (!UpdateVictim())
				return;

			m_events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = m_events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_CHECK_FACTION:
					if (roll_chance_i(10))
					{
						me->UpdateEntry(MOB_CAPTURED_MINER_FRIENDLY);
						//2fix if (Creature* crushto = ObjectAccessor::GetCreature(*me, m_instance->GetData64(DATA_CRUSHTO)))
							//2fix me->SetInCombatWith(crushto);
					}
					else
					{
						m_events.ScheduleEvent(EVENT_CHECK_FACTION, 10 * IN_MILLISECONDS);
					}
					break;

				case EVENT_TRAUMATIC_STRIKE:
					switch (me->getFaction())
					{
					case FACTION_HOSTILE:
						DoCastVictim(SPELL_TRAUMATIC_STRIKE_PLAYERS);
						break;

					case FACTION_FRIENDLY:
						DoCastVictim(SPELL_TRAUMATIC_STRIKE_BOSS);
						break;

					default:
						break;
					}
					m_events.ScheduleEvent(EVENT_TRAUMATIC_STRIKE, 10 * IN_MILLISECONDS);
					break;

				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

	private:
		EventMap        m_events;
		InstanceScript* m_instance;
	};

	CreatureAI* GetAI(Creature *creature) const
	{
		return GetBloodmaulSlagAI<mob_captured_miner_AI, Creature>(creature);
	}
};



void AddSC_boss_slave_watcher_crushto()
{
	new boss_slave_watcher_crushto();
	new mob_captured_miner();

}

