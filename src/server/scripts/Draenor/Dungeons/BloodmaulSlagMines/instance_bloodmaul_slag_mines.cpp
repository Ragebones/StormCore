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
#include "bloodmaul_slag_mines.h"

/*

INSERT INTO instance_template (map, parent, script, allowMount) VALUES
(1175, 0, "instance_bloodmaul_slag_mines", 0);

*/

class instance_bloodmaul_slag_mines : public InstanceMapScript
{
    public:
        instance_bloodmaul_slag_mines() : InstanceMapScript("instance_bloodmaul_slag_mines", 1175) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_bloodmaul_slag_mines_InstanceMapScript(map);
        }

        struct instance_bloodmaul_slag_mines_InstanceMapScript : public InstanceScript
        {
            instance_bloodmaul_slag_mines_InstanceMapScript(Map* map) : InstanceScript(map) { }

            bool IsBossDead[DATA_MAX_ENCOUNTERS];

            ObjectGuid RoltallGUID;
            ObjectGuid CrushtoGUID;
            ObjectGuid GugrokkGUID;

            void Initialize() override
            {
                memset(&IsBossDead, false, sizeof(IsBossDead));

				RoltallGUID = ObjectGuid::Empty;
				CrushtoGUID = ObjectGuid::Empty;
                GugrokkGUID = ObjectGuid::Empty;

            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_ROLTALL:
                        RoltallGUID = creature->GetGUID();
                        break;

                    case BOSS_CRUSHTO:
                        CrushtoGUID = creature->GetGUID();
                        break;

                    case BOSS_GUGROKK:
                        GugrokkGUID = creature->GetGUID();
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ROLTALL:
                        if (IsBossDead[DATA_ROLTALL])
                            return 1;
                        break;

                    case DATA_CRUSHTO:
                        if (IsBossDead[DATA_CRUSHTO])
                            return 1;
                        break;

                    case DATA_GUGROKK:
                        if (IsBossDead[DATA_GUGROKK])
                            return 1;
                        break;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 identifier) const override
            {
                switch (identifier)
                {
                    case DATA_ROLTALL:
                        return RoltallGUID;

                    case DATA_CRUSHTO:
                        return CrushtoGUID;

                    case DATA_GUGROKK:
                        return GugrokkGUID;

                    default:
                        break;
                }

				return ObjectGuid::Empty;
            }
			
            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_ROLTALL:
                        IsBossDead[DATA_ROLTALL] = true;
                        break;

                    case DATA_CRUSHTO:
                        IsBossDead[DATA_CRUSHTO] = true;
                        break;

                    case DATA_GUGROKK:
                        IsBossDead[DATA_GUGROKK] = true;
                        break;
                }
            }
        };

};

void AddSC_instance_bloodmaul_slag_mines()
{ 
    new instance_bloodmaul_slag_mines();
}
