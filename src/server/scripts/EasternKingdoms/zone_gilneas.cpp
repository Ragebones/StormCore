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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"
#include "WorldSession.h"

class PlayerLoginScript : public PlayerScript
{
public:
    PlayerLoginScript() : PlayerScript("PlayerLoginScript") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        if (player->GetMapId() == 654 && player->GetPhaseMask() == 1)
        {
            std::set<uint32> terrainswap;
            terrainswap.insert(638);

            std::set<uint32> phaseIds;
            phaseIds.insert(170);

            std::set<uint32> worldMapAreaSwaps;

            player->GetSession()->SendSetPhaseShift(phaseIds, terrainswap, worldMapAreaSwaps);
        }
    }
};

void AddSC_gilneas()
{
    new PlayerLoginScript();
}
