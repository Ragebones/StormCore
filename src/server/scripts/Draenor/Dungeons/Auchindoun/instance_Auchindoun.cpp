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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Auchindoun.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "SpellScript.h"
#include "MoveSplineInit.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

Position const spawn_azakel = { 1910.64f, 2765.01f, 31.41f, 4.72f };
std::set<ObjectGuid> guids;
std::set<ObjectGuid> guids_phase;
std::set<ObjectGuid> guids_atKaathar;
bool summon_check;
class instance_auchindoun : public InstanceMapScript
{
public:
    instance_auchindoun() : InstanceMapScript(Auscriptname, 1182) { }

    struct instance_auchindoun_InstanceMapScript : public InstanceScript
    {
        instance_auchindoun_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(encounternumber);
            guids.clear();
            guids_phase.clear();
            guids_atKaathar.clear();
            summon_check = false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_KATHAAR:
                KathaarGUID = creature->GetGUID();
                break;
            case NPC_NIAMI:
                NiamiGUID = creature->GetGUID();
                break;
            case NPC_AZAKEL:
                AzakelGUID = creature->GetGUID();
                break;
            case NPC_TERON:
                TeronGUID = creature->GetGUID();
                break;
            case NPC_SOUL_AEGIS:
                SoulAegisGUID = creature->GetGUID();
                break;
            case NPC_FELGUARD:
                FelguardGUID = creature->GetGUID();
                guids.insert(FelguardGUID);
                break;
            case NPC_PIROMANIAC:
                PiromaniacGUID = creature->GetGUID();
                guids.insert(PiromaniacGUID);
                break;
            case NPC_AUCHENAI_DEFENDER:
                AuchenaiDefenderGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiDefenderGUID);
                break;
            case NPC_AUCHENAI_PRIEST:
                AuchenaiPriestGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiPriestGUID);
                break;
            case NPC_AUCHENAI_ARBITER:
                AuchenaiArbiterGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiArbiterGUID);
                break;
            case NPC_AUCHENAI_MAGUS:
                AuchenaiMagusGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiMagusGUID);
                break;
            case NPC_AUCHENAI_ZEALOT:
                AuchenaiZealotGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiZealotGUID);
                break;
            case NPC_AUCHENAI_HOPLITE:
                AuchenaiHopliteGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiHopliteGUID);
                break;
            case NPC_AUCHENAI_WARDEN:
                AuchenaiWardenGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiWardenGUID);
                break;
            case NPC_AUCHENAI_RITUALIST:
                AuchenaiRitualustGUID = creature->GetGUID();
                guids_phase.insert(AuchenaiRitualustGUID);
                break;
            case NPC_SARGEREI_HOPLITE:
                SargeraiHopliteGUID = creature->GetGUID();
                guids_atKaathar.insert(SargeraiHopliteGUID);
                break;
            case NPC_SARGEREI_RITUALIST:
                SargeraiRitualistGUID = creature->GetGUID();
                guids_atKaathar.insert(SargeraiRitualistGUID);
                break;
            case NPC_SARGEREI_ZEALOT:
                SargeraiZealotGUID = creature->GetGUID();
                guids_atKaathar.insert(SargeraiZealotGUID);
                break;
            case NPC_SPIRIT_TENDER:
                SargeraiSpirit_TenderGUID = creature->GetGUID();
                guids_atKaathar.insert(SargeraiSpirit_TenderGUID);
                break;
            case NPC_CLERIC:
                SargeraiCliricGUID = creature->GetGUID();
                guids_atKaathar.insert(SargeraiCliricGUID);
                break;
            case NPC_SOUL_DEFENDER:
                SargeraiSoulbinderGUID = creature->GetGUID();
                guids_atKaathar.insert(SargeraiSoulbinderGUID);
                break;
            default:
                break;
            }
        }
        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_KAATHAR:
                return KathaarGUID;
            case DATA_NIAMI:
                return NiamiGUID;
            case DATA_AZAKEL:
                return AzakelGUID;
            case DATA_TERON:
                return TeronGUID;
            default:
                break;
            }
            return ObjectGuid::Empty;
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;
            switch (creature->GetEntry())
            {
            case NPC_FELGUARD:
                guids.erase(creature->GetGUID());
                if ((guids.size() == 0) && (!summon_check))
                {
                    creature->SummonCreature(NPC_AZAKEL, spawn_azakel, TEMPSUMMON_MANUAL_DESPAWN);
                    summon_check = true;
                }
                break;
            case NPC_PIROMANIAC:
                guids.erase(creature->GetGUID());
                if ((guids.size() == 0) && (!summon_check))
                {
                    creature->SummonCreature(NPC_AZAKEL, spawn_azakel, TEMPSUMMON_MANUAL_DESPAWN);
                    summon_check = true;
                }
                break;
            case NPC_SARGEREI_HOPLITE:
                guids_atKaathar.erase(creature->GetGUID());
                if (guids_atKaathar.size() == 0)
                    if (Creature* Kaathar = instance->GetCreature(KathaarGUID))
                    {
                        Kaathar->setActive(true);
                        Kaathar->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                break;
            case NPC_SARGEREI_RITUALIST:
                guids_atKaathar.erase(creature->GetGUID());
                if (guids_atKaathar.size() == 0)
                    if (Creature* Kaathar = instance->GetCreature(KathaarGUID))
                    {
                        Kaathar->setActive(true);
                        Kaathar->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                break;
            case NPC_SARGEREI_ZEALOT:
                guids_atKaathar.erase(creature->GetGUID());
                if (guids_atKaathar.size() == 0)
                    if (Creature* Kaathar = instance->GetCreature(KathaarGUID))
                    {
                        Kaathar->setActive(true);
                        Kaathar->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                break;
            case NPC_SOUL_DEFENDER:
                guids_atKaathar.erase(creature->GetGUID());
                if (guids_atKaathar.size() == 0)
                    if (Creature* Kaathar = instance->GetCreature(KathaarGUID))
                    {
                        Kaathar->setActive(true);
                        Kaathar->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                break;
            case NPC_CLERIC:
                guids_atKaathar.erase(creature->GetGUID());
                if (guids_atKaathar.size() == 0)
                    if (Creature* Kaathar = instance->GetCreature(KathaarGUID))
                    {
                        Kaathar->setActive(true);
                        Kaathar->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                break;
            case NPC_SPIRIT_TENDER:
                guids_atKaathar.erase(creature->GetGUID());
                if (guids_atKaathar.size() == 0)
                    if (Creature* Kaathar = instance->GetCreature(KathaarGUID))
                    {
                        Kaathar->setActive(true);
                        Kaathar->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                break;
            default:
                break;
            }
        }
        
        void Spawn(Creature* me, uint32 type)
        {
            switch (type)
            {
            case NPC_SARGERAI_DEFENDER:
                for (uint32 i = 0; i < defenders_val; i++)
                    me->SummonCreature(NPC_SARGERAI_DEFENDER, defender_spawn[i], TEMPSUMMON_MANUAL_DESPAWN);
                break;
            case NPC_SARGERAI_SOULBINDER:
                for (uint32 i = 0; i < soulbinder_val; i++)
                    me->SummonCreature(NPC_SARGERAI_SOULBINDER, Soulbinder_spawn[i], TEMPSUMMON_MANUAL_DESPAWN);
                break;
            case NPC_SARGERAI_MAGE:
                for (uint32 i = 0; i < magus_val; i++)
                    me->SummonCreature(NPC_SARGERAI_MAGE, Magus_spawn[i], TEMPSUMMON_MANUAL_DESPAWN);
                break;
            case NPC_SARGERAI_GUARD:
                me->SummonCreature(NPC_SARGERAI_GUARD, Guard_spawn, TEMPSUMMON_MANUAL_DESPAWN);
                break;
            default:
                break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;
            switch (type)
            {
            case BOSS_KAATHAR:
                if (state == DONE)
                {
                    if (Creature* Niami = instance->GetCreature(NiamiGUID))
                    {
                        Niami->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        Niami->SetDisplayId(53089);
                        Niami->setFaction(14);
                        Spawn(Niami, NPC_SARGERAI_DEFENDER);
                        Spawn(Niami, NPC_SARGERAI_SOULBINDER);
                        Spawn(Niami, NPC_SARGERAI_MAGE);
                        Spawn(Niami, NPC_SARGERAI_GUARD);
                    }
                    for (std::set<ObjectGuid>::iterator itr = guids_phase.begin(); itr != guids_phase.end(); ++itr)
                    {
                        if (Creature* creature = instance->GetCreature(*itr))
                            creature->DespawnOrUnsummon();
                    }
                }
                break;
            default:
                break;
            }
            return true;
        }
    protected:
        ObjectGuid KathaarGUID;
        ObjectGuid NiamiGUID;
        ObjectGuid AzakelGUID;
        ObjectGuid TeronGUID;
        ObjectGuid FelguardGUID;
        ObjectGuid PiromaniacGUID;
        ObjectGuid BlazingTricksterGUID;
        ObjectGuid AuchenaiDefenderGUID;
        ObjectGuid AuchenaiPriestGUID;
        ObjectGuid AuchenaiArbiterGUID;
        ObjectGuid AuchenaiMagusGUID;
        ObjectGuid AuchenaiZealotGUID;
        ObjectGuid AuchenaiHopliteGUID;
        ObjectGuid AuchenaiWardenGUID;
        ObjectGuid AuchenaiRitualustGUID;
        ObjectGuid SoulAegisGUID;
        ObjectGuid SargeraiRitualistGUID;
        ObjectGuid SargeraiZealotGUID;
        ObjectGuid SargeraiHopliteGUID;
        ObjectGuid SargeraiSoulbinderGUID;
        ObjectGuid SargeraiCliricGUID;
        ObjectGuid SargeraiSpirit_TenderGUID;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_auchindoun_InstanceMapScript(map);
    }
};

void AddSC_instance_auchindoun()
{
    new instance_auchindoun();
}
