/*
 * Copyright (C) 2016-2017 StormCore
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

/*
 * Scripts for spells with SPELLFAMILY_MONK and SPELLFAMILY_GENERIC spells used by monk players.
 * Scriptnames of files in this file should be prefixed with "spell_monk_".
 */

#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum MonkSpells
{
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL         = 117952,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC        = 123333,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK       = 117962,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD    = 117953,
    SPELL_MONK_PROVOKE_SINGLE_TARGET                    = 116189,
    SPELL_MONK_PROVOKE_AOE                              = 118635,
    SPELL_MONK_SOOTHING_MIST                            = 115175,
    SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE             = 154436,
    SPELL_MONK_SURGING_MIST_HEAL                        = 116995,
    SPELL_MONK_RENEWING_MIST                            = 115151,
    SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL              = 119611,
    SPELL_MONK_RENEWING_MIST_TARGET_SELECT              = 119607,
    SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL               = 119647,
    SPELL_MONK_GLYPH_OF_FORTIFYING_BREW                 = 124997,
    SPELL_MONK_FORTIFYING_BREW_AURA                     = 120954,
    SPELL_MONK_EXPEL_HARM_AREA_DMG                      = 115129,
    SPELL_MONK_ROLL                                     = 109132,
    SPELL_MONK_ROLL_TRIGGER                             = 107427,
    SPELL_MONK_RING_OF_PEACE_AURA                       = 142895,
    SPELL_MONK_RING_OF_PEACE_DISARM                     = 137461,
    SPELL_MONK_RING_OF_PEACE_SILENCE                    = 137460,
    SPELL_MONK_ZEN_PILGRIMAGE                           = 126892,
    SPELL_MONK_ZEN_PILGRIMAGE_RETURN                    = 126895,
    SPELL_AURA_ZEN_PILGRIMAGE_RETURN                    = 126896,
    SPELL_AURA_TOUCH_OF_DEATH                           = 124490

};

// 117952 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning : public SpellScriptLoader
{
public:
    spell_monk_crackling_jade_lightning() : SpellScriptLoader("spell_monk_crackling_jade_lightning") { }

    class spell_monk_crackling_jade_lightning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC))
                return false;
            return true;
        }

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->HasAura(SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE))
                    caster->CastSpell(caster, SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_crackling_jade_lightning_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_AuraScript();
    }
};

// 117959 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning_knockback_proc_aura : public SpellScriptLoader
{
public:
    spell_monk_crackling_jade_lightning_knockback_proc_aura() : SpellScriptLoader("spell_monk_crackling_jade_lightning_knockback_proc_aura") { }

    class spell_monk_crackling_jade_lightning_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (GetTarget()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
                return false;

            if (eventInfo.GetActor()->GetGUID() != GetTarget()->GetChannelObjectGuid())
                return false;

            Spell* currentChanneledSpell = GetTarget()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
            if (!currentChanneledSpell || currentChanneledSpell->GetSpellInfo()->Id != SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL)
                return false;

            return true;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK, TRIGGERED_FULL_MASK);
            GetTarget()->CastSpell(GetTarget(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_aura_AuraScript();
    }
};

// 115546 - Provoke
class spell_monk_provoke : public SpellScriptLoader
{
public:
    spell_monk_provoke() : SpellScriptLoader("spell_monk_provoke") { }

    class spell_monk_provoke_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_provoke_SpellScript);

        static uint32 const BlackOxStatusEntry = 61146;

        bool Validate(SpellInfo const* spellInfo) override
        {
            if (!(spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT_MASK)) // ensure GetExplTargetUnit() will return something meaningful during CheckCast
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_PROVOKE_SINGLE_TARGET))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_PROVOKE_AOE))
                return false;
            return true;
        }

        SpellCastResult CheckExplicitTarget()
        {
            if (GetExplTargetUnit()->GetEntry() != BlackOxStatusEntry)
            {
                SpellInfo const* singleTarget = sSpellMgr->AssertSpellInfo(SPELL_MONK_PROVOKE_SINGLE_TARGET);
                SpellCastResult singleTargetExplicitResult = singleTarget->CheckExplicitTarget(GetCaster(), GetExplTargetUnit());
                if (singleTargetExplicitResult != SPELL_CAST_OK)
                    return singleTargetExplicitResult;
            }
            else if (GetExplTargetUnit()->GetOwnerGUID() != GetCaster()->GetGUID())
                return SPELL_FAILED_BAD_TARGETS;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            if (GetHitUnit()->GetEntry() != BlackOxStatusEntry)
                GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_PROVOKE_SINGLE_TARGET, true);
            else
                GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_PROVOKE_AOE, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_monk_provoke_SpellScript::CheckExplicitTarget);
            OnEffectHitTarget += SpellEffectFn(spell_monk_provoke_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_provoke_SpellScript();
    }
};

// 116694 - Surging Mist
class spell_monk_surging_mist : public SpellScriptLoader
{
    public:
        spell_monk_surging_mist() : SpellScriptLoader("spell_monk_surging_mist") { }

        class spell_monk_surging_mist_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_surging_mist_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_SURGING_MIST_HEAL))
                    return false;
                return true;
            }

            void SelectTarget(WorldObject*& target)
            {
                Unit* caster = GetCaster();
                if (caster->GetUInt32Value(UNIT_CHANNEL_SPELL) == SPELL_MONK_SOOTHING_MIST)
                    if (Unit* soothingMistTarget = ObjectAccessor::GetUnit(*caster, caster->GetChannelObjectGuid()))
                        target = soothingMistTarget;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_SURGING_MIST_HEAL, true);
            }

            void Register() override
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_monk_surging_mist_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_TARGET_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_monk_surging_mist_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_surging_mist_SpellScript();
        }
};

// 123273 - Surging Mist (Glyphed)
class spell_monk_surging_mist_glyphed : public SpellScriptLoader
{
public:
    spell_monk_surging_mist_glyphed() : SpellScriptLoader("spell_monk_surging_mist_glyphed") { }

    class spell_monk_surging_mist_glyphed_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_surging_mist_glyphed_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_SURGING_MIST_HEAL))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_SOOTHING_MIST))
                return false;
            return true;
        }

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            if (caster->GetUInt32Value(UNIT_CHANNEL_SPELL) == SPELL_MONK_SOOTHING_MIST)
            {
                targets.clear();
                if (Unit* soothingMistTarget = ObjectAccessor::GetUnit(*caster, caster->GetChannelObjectGuid()))
                    targets.push_back(soothingMistTarget);
            }
            else
            {
                targets.remove_if([caster](WorldObject* target)
                {
                    return target->GetTypeId() != TYPEID_UNIT || !target->ToUnit()->IsInRaidWith(caster);
                });
                targets.sort(Trinity::HealthPctOrderPred());
                if (!targets.empty())
                    targets.resize(1);
            }

            if (targets.empty())
                targets.push_back(caster);
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_SURGING_MIST_HEAL, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_surging_mist_glyphed_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            OnEffectHitTarget += SpellEffectFn(spell_monk_surging_mist_glyphed_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_surging_mist_glyphed_SpellScript();
    }
};

// 115151 - Renewing Mist
class spell_monk_renewing_mist : public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist() : SpellScriptLoader("spell_monk_renewing_mist") { }

        class spell_monk_renewing_mist_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_renewing_mist_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_TARGET_SELECT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_renewing_mist_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_renewing_mist_SpellScript();
        }
};

// 119611 - Renewing Mist Periodic Heal
class spell_monk_renewing_mist_periodic_heal : public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist_periodic_heal() : SpellScriptLoader("spell_monk_renewing_mist_periodic_heal") { }

        class spell_monk_renewing_mist_periodic_heal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_renewing_mist_periodic_heal_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_TARGET_SELECT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL))
                    return false;
                return true;
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (aurEff->GetBase()->GetCharges() > 1)
                    if (Unit* originCaster = GetCaster())
                        originCaster->CastSpell(GetTarget(), SPELL_MONK_RENEWING_MIST_TARGET_SELECT, true);
            }

            void HandleDummy(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                aurEff->GetBase()->SetCharges(aurEff->GetAmount());
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_renewing_mist_periodic_heal_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
                OnEffectApply += AuraEffectApplyFn(spell_monk_renewing_mist_periodic_heal_AuraScript::HandleDummy, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_monk_renewing_mist_periodic_heal_AuraScript();
        }
};

// 119607 - Renewing Mist Target Selection
class spell_monk_renewing_mist_target_selector : public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist_target_selector() : SpellScriptLoader("spell_monk_renewing_mist_target_selector") { }

        class spell_monk_renewing_mist_target_selector_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_renewing_mist_target_selector_SpellScript);

        public:
            spell_monk_renewing_mist_target_selector_SpellScript() { }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_TARGET_SELECT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetWorldObject());
                if (targets.empty())
                    return;
                targets.sort(Trinity::HealthPctOrderPred());
                targets.resize(1);
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    if (Aura* aura = GetExplTargetUnit()->GetAura(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL, GetCaster()->GetGUID()))
                        if (AuraEffect* effect = aura->GetEffect(EFFECT_1))
                        {
                            GetExplTargetUnit()->CastSpell(target, SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL, true);
                            aura->SetCharges(0);
                            int32 bp1 = std::max(0, effect->GetAmount() - 1);
                            GetExplTargetUnit()->CastCustomSpell(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL, SPELLVALUE_BASE_POINT1, bp1, target, true, 0, effect, GetCaster()->GetGUID());
                        }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_renewing_mist_target_selector_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_monk_renewing_mist_target_selector_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_renewing_mist_target_selector_SpellScript();
        }
};

class spell_monk_fortifying_brew : public SpellScriptLoader
{
    public:
    spell_monk_fortifying_brew() : SpellScriptLoader("spell_monk_fortifying_brew")
    { }

    class spell_monk_fortifying_brew_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_fortifying_brew_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_FORTIFYING_BREW_AURA) || !sSpellMgr->GetSpellInfo(SPELL_MONK_GLYPH_OF_FORTIFYING_BREW))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
            {
                int32 bp0 = GetEffectValue();
                int32 bp1 = -bp0;

                if (Aura* aura = target->GetAura(SPELL_MONK_GLYPH_OF_FORTIFYING_BREW))
                {
                    bp0 -= aura->GetEffect(EFFECT_1)->GetAmount();
                    bp1 -= aura->GetEffect(EFFECT_0)->GetAmount();
                }

                bp0 = CalculatePct(target->GetMaxHealth(), bp0);
                target->CastCustomSpell(target, SPELL_MONK_FORTIFYING_BREW_AURA, &bp0, &bp1, NULL, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_fortifying_brew_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_fortifying_brew_SpellScript();
    }
};

class spell_monk_expel_harm : public SpellScriptLoader
{
    public:
        spell_monk_expel_harm() : SpellScriptLoader("spell_monk_expel_harm") { }

        class spell_monk_expel_harm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_expel_harm_SpellScript);

            void HandleOnHit()
            {
                if (auto caster = GetCaster())
                {
                    int32 bp = CalculatePct(GetHitHeal(), 50);
                    caster->CastCustomSpell(caster, SPELL_MONK_EXPEL_HARM_AREA_DMG, &bp, NULL, NULL, true);
                }
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_monk_expel_harm_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_expel_harm_SpellScript();
        }
};

class spell_monk_roll : public SpellScriptLoader
{
public:
    spell_monk_roll() : SpellScriptLoader("spell_monk_roll") { }

    class spell_monk_roll_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_roll_SpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ROLL_TRIGGER))
                return false;
            return true;
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void HandleBeforeCast()
        {
            Aura* aura = GetCaster()->AddAura(SPELL_MONK_ROLL_TRIGGER, GetCaster());
            if (!aura)
                return;

            AuraApplication* app = aura->GetApplicationOfTarget(GetCaster()->GetGUID());
            if (!app)
                return;

            app->ClientUpdate();
        }

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            caster->CastSpell(caster, SPELL_MONK_ROLL_TRIGGER, true);
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_monk_roll_SpellScript::HandleBeforeCast);
            AfterCast += SpellCastFn(spell_monk_roll_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_roll_SpellScript();
    }
};

class spell_monk_ring_of_peace_dummy : public SpellScriptLoader
{
    public:
        spell_monk_ring_of_peace_dummy() : SpellScriptLoader("spell_monk_ring_of_peace_dummy") {}

        class spell_monk_ring_of_peace_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_ring_of_peace_dummy_AuraScript);

             void HandleDummyProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetTarget())
                    {
                        caster->CastSpell(target, SPELL_MONK_RING_OF_PEACE_SILENCE, true);
                        caster->CastSpell(target, SPELL_MONK_RING_OF_PEACE_DISARM, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_monk_ring_of_peace_dummy_AuraScript::HandleDummyProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_monk_ring_of_peace_dummy_AuraScript();
        }
};

class spell_monk_ring_of_peace : public SpellScriptLoader
{
    public:
        spell_monk_ring_of_peace() : SpellScriptLoader("spell_monk_ring_of_peace") { }

        class spell_monk_ring_of_peace_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_ring_of_peace_AuraScript);

            void OnUpdate(uint32 /*diff*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetUnitOwner())
                    {
                        std::list<Unit*> targetList;
                        float radius = 8.0f;

                        Trinity::NearestAttackableUnitInObjectRangeCheck u_check(target, caster, radius);
                        Trinity::UnitListSearcher<Trinity::NearestAttackableUnitInObjectRangeCheck> searcher(target, targetList, u_check);
                        target->VisitNearbyObject(radius, searcher);

                        for (auto itr : targetList)
                            caster->CastSpell(itr, SPELL_MONK_RING_OF_PEACE_AURA, true);
                    }
                }
            }

            void Register() override
            {
                OnAuraUpdate += AuraUpdateFn(spell_monk_ring_of_peace_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_monk_ring_of_peace_AuraScript();
        }
};

// Transcendence : Transfer - 119996
class spell_monk_transcendence_transfer: public SpellScriptLoader
{
    public:
        spell_monk_transcendence_transfer() : SpellScriptLoader("spell_monk_transcendence_transfer") { }

        class spell_monk_transcendence_transfer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_transcendence_transfer_SpellScript);

            SpellCastResult CheckSpiritRange()
            {
                if (Unit* caster = GetCaster())
                {
                    for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                    {
                        if ((*itr)->GetEntry() == 54569)
                        {
                            if ((*itr)->GetDistance(caster) > 40.0f)
                                return SPELL_FAILED_DONT_REPORT;
                        }
                    }
                }

                return SPELL_CAST_OK;
            }

            void HandleDummy()
            {
                if (Unit* caster = GetCaster())
                {
                    for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                    {
                        if ((*itr)->GetEntry() == 54569)
                        {
                            Creature* clone = (*itr)->ToCreature();
                            if (clone && clone->AI())
                                clone->AI()->DoAction(1);
                        }
                    }
                }
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_transcendence_transfer_SpellScript::CheckSpiritRange);
                OnHit += SpellHitFn(spell_monk_transcendence_transfer_SpellScript::HandleDummy);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_transcendence_transfer_SpellScript();
        }
};

// Zen Pilgrimage - 126892 and Zen Pilgrimage : Return - 126895
class spell_monk_zen_pilgrimage : public SpellScriptLoader
{
    public:
        spell_monk_zen_pilgrimage() : SpellScriptLoader("spell_monk_zen_pilgrimage") { }

        class spell_monk_zen_pilgrimage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_zen_pilgrimage_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE) || !sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE_RETURN))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        /*float x = _player->GetPositionX();
                        float y = _player->GetPositionY();
                        float z = _player->GetPositionZ();
                        float o = _player->GetOrientation();*/

                        if (GetSpellInfo()->Id == SPELL_MONK_ZEN_PILGRIMAGE)
                        {
                            _player->SaveRecallPosition();
                            _player->TeleportTo(870, 3818.55f, 1793.18f, 950.35f, _player->GetOrientation());
                        }
                        else if (GetSpellInfo()->Id == SPELL_MONK_ZEN_PILGRIMAGE_RETURN)
                        {
                            //_player->Relocate(x, y, z, o); NEED FIX
                            _player->RemoveAura(SPELL_AURA_ZEN_PILGRIMAGE_RETURN);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_zen_pilgrimage_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_zen_pilgrimage_SpellScript();
        }
};

// last update : 7.1.0 23222
// Touch of Death - 115080
class spell_monk_touch_of_death: public SpellScriptLoader
{
    public:
        spell_monk_touch_of_death() : SpellScriptLoader("spell_monk_touch_of_death") { }

        class spell_monk_touch_of_death_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_touch_of_death_SpellScript);

            SpellCastResult CheckCast()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetExplTargetUnit())
                    {
                        if (caster->HasAura(SPELL_AURA_TOUCH_OF_DEATH))
                        {
                            if (target->GetTypeId() == TYPEID_UNIT && !target->GetOwner() && target->GetHealthPct() > 50.0f && (target->GetHealth() > caster->GetMaxHealth()))
                                return SPELL_FAILED_BAD_TARGETS;
                            else if (((target->GetOwner() && target->GetOwner()->ToPlayer()) || target->GetTypeId() == TYPEID_PLAYER) &&
                                (target->GetHealthPct() > 50.0f))
                                return SPELL_FAILED_BAD_TARGETS;
                        }
                        else
                        {
                            if ((target->GetTypeId() == TYPEID_PLAYER || (target->GetOwner() && target->GetOwner()->ToPlayer())) && target->GetHealthPct() > 50.0f)
                                return SPELL_FAILED_BAD_TARGETS;
                            else if (target->GetTypeId() == TYPEID_UNIT && target->GetHealthPct() > 50.0f && target->GetHealth() > caster->GetMaxHealth())
                                return SPELL_FAILED_BAD_TARGETS;
                        }
                        return SPELL_CAST_OK;
                    }
                }

                return SPELL_FAILED_NO_VALID_TARGETS;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_touch_of_death_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_touch_of_death_SpellScript();
        }
};

void AddSC_monk_spell_scripts()
{
    new spell_monk_crackling_jade_lightning();
    new spell_monk_crackling_jade_lightning_knockback_proc_aura();
    new spell_monk_provoke();
    new spell_monk_surging_mist();
    new spell_monk_surging_mist_glyphed();
    new spell_monk_renewing_mist();
    new spell_monk_renewing_mist_periodic_heal();
    new spell_monk_renewing_mist_target_selector();
    new spell_monk_fortifying_brew();
    new spell_monk_expel_harm();
    new spell_monk_roll();
    new spell_monk_ring_of_peace_dummy();
    new spell_monk_ring_of_peace();
    new spell_monk_transcendence_transfer();
    new spell_monk_zen_pilgrimage();
    new spell_monk_touch_of_death();
}
