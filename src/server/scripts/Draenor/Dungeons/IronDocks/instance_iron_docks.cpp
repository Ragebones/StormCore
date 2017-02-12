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
#include "iron_docks.h"

class instance_iron_docks : public InstanceMapScript
{
    public:
        instance_iron_docks() : InstanceMapScript(IronDocksScriptName, 1195) { }

        struct instance_iron_docks_InstanceScript : public InstanceScript
        {
            instance_iron_docks_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_SKULLOC:
                        creature->setActive(true);
                        SkullocGUID = creature->GetGUID();
                        break;
                    case BOSS_KORAMAR:
                        creature->setActive(true);
                        KoramarGUID = creature->GetGUID();
                        break;
                    case BOSS_ZOGGOSH:
                        creature->setActive(true);
                        ZoggoshGUID = creature->GetGUID();
                        break;
                    case BOSS_FLESHRENDER_NOKGAR:
                        NokgarGUID = creature->GetGUID();
                        break;
                    case BOSS_DREADFANG:
                        DreadfangGUID = creature->GetGUID();
                        break;
                    case NPC_ENGINE:
                        creature->SetDisplayId(creature->GetCreatureTemplate()->Modelid2);
                        break;
                    case NPC_GROMKAR_FLAMESLINGER:
                        creature->SetDisableGravity(true);
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_FLESHRENDER_NOKGAR:
                        return NokgarGUID;
                    case DATA_DREADFANG:
                        return DreadfangGUID;
                    case DATA_KORAMAR:
                        return KoramarGUID;
                    case DATA_SKULLOC:
                        return SkullocGUID;
                    break;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            void OnPlayerEnter(Player* player) override
            {
                DoUpdateWorldState(9232, 1);

            }

        private:
            ObjectGuid KoramarGUID;
            ObjectGuid SkullocGUID;
            ObjectGuid ZoggoshGUID;
            ObjectGuid NokgarGUID;
            ObjectGuid DreadfangGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_iron_docks_InstanceScript(map);
        }
};

void AddSC_instance_iron_docks()
{
    new instance_iron_docks();
}
