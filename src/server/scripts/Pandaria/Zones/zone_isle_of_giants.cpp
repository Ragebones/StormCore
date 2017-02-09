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
#include "CreatureTextMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"

enum Spells
{
    SPELL_CRUSH                     = 137504,
    SPELL_FRILL_BLAST               = 137505,
    SPELL_GROWING_FURY              = 137502,
    SPELL_PIERCING_ROAR             = 137457,
    SPELL_SPIRITFIRE_BEAM_1         = 137508,
    SPELL_SPIRITFIRE_BEAM_2         = 137511,
    SPELL_SPIRITFIRE_BEAM_3         = 139895,
    SPELL_ALPHA_MALE                = 138391,
    SPELL_TANK_THREAT_MULTIPLIER    = 138390
};

enum Events
{
    EVENT_CRUSH             = 1,
    EVENT_FRILL_BLAST,
    EVENT_GROWING_FURY,
    EVENT_PIERCING_ROAR,
    EVENT_SPIRITFIRE_BEAM
};

class boss_oondasta : public CreatureScript
{
    public:
        boss_oondasta() : CreatureScript("boss_oondasta") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_oondastaAI(creature);
        }

        struct boss_oondastaAI : public ScriptedAI
        {
            EventMap events;

            boss_oondastaAI(Creature* creature) : ScriptedAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

                me->setActive(true);

                me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 30.0f);
                me->SetFloatValue(UNIT_FIELD_COMBATREACH, 30.0f);
            }

            void Reset() override
            {
                events.Reset();

                me->SetReactState(REACT_AGGRESSIVE);
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                me->AddAura(SPELL_ALPHA_MALE, me);

                events.ScheduleEvent(EVENT_CRUSH, urand(10000, 15000));
                events.ScheduleEvent(EVENT_GROWING_FURY, 30000);
                events.ScheduleEvent(EVENT_PIERCING_ROAR, urand(25000, 30000));
                events.ScheduleEvent(EVENT_FRILL_BLAST, urand(25000, 40000));
                events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM, urand(10000, 15000));
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSH:
                            DoCastVictim(SPELL_CRUSH);
                            events.ScheduleEvent(EVENT_CRUSH, urand(25000, 30000));
                            break;
                        case EVENT_GROWING_FURY:
                            DoCast(me, SPELL_GROWING_FURY);
                            events.ScheduleEvent(EVENT_GROWING_FURY, 30000);
                            break;
                        case EVENT_PIERCING_ROAR:
                            DoCastAOE(SPELL_PIERCING_ROAR);
                            events.ScheduleEvent(EVENT_PIERCING_ROAR, urand(25000, 30000));
                            break;
                        case EVENT_FRILL_BLAST:
                            DoCastAOE(SPELL_FRILL_BLAST);
                            events.ScheduleEvent(EVENT_FRILL_BLAST, urand(25000, 40000));
                            break;
                        case EVENT_SPIRITFIRE_BEAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SPIRITFIRE_BEAM_1);
                            events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM, urand(10000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class spell_oundasta_tank_threat_multiplier : public SpellScriptLoader
{
    public:
        spell_oundasta_tank_threat_multiplier() : SpellScriptLoader("spell_oundasta_tank_threat_multiplier") { }

        class spell_oundasta_tank_threat_multiplier_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_oundasta_tank_threat_multiplier_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    if (Unit* target = pCreature->AI()->SelectTarget(SELECT_TARGET_FARTHEST, 0, 0.0f, true))
                    {
                        targets.clear();
                        targets.push_back(target);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_oundasta_tank_threat_multiplier_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:

            class TanksCheck
            {
                public:
                    TanksCheck() {}
        
                    bool operator()(WorldObject* unit)
                    {
                        if (unit->GetTypeId() != TYPEID_PLAYER)
                            return true;

                        switch (unit->ToPlayer()->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID))
                        {
                            case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                            case TALENT_SPEC_DEATHKNIGHT_FROST:
                            case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
                            case TALENT_SPEC_PALADIN_PROTECTION:
                            case TALENT_SPEC_PALADIN_RETRIBUTION:
                            case TALENT_SPEC_WARRIOR_ARMS:
                            case TALENT_SPEC_WARRIOR_FURY:
                            case TALENT_SPEC_WARRIOR_PROTECTION:
                            case TALENT_SPEC_MONK_BREWMASTER:
                            case TALENT_SPEC_DRUID_BEAR:
                            case TALENT_SPEC_DEMON_HUNTER_VENGEANCE: // 7.x.x Demon Hunter tank role
                                return false;
                        }

                        return true;
                    }
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_oundasta_tank_threat_multiplier_SpellScript();
        }
};

void AddSC_zone_isle_of_giants()
{
    new boss_oondasta();
    new spell_oundasta_tank_threat_multiplier();
}
