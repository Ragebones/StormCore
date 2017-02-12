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

#ifndef IRON_DOCKS_H_
#define IRON_DOCKS_H_

#include "Map.h"
#include "CreatureAI.h"

#define DataHeader "ID"
#define IronDocksScriptName "instance_iron_docks"

uint32 const EncounterCount = 4;

enum DataTypes
{
    DATA_FLESHRENDER_NOKGAR = 0,
    DATA_DREADFANG          = 1,
    DATA_GRIMRAIL_ENFORCER  = 2,
    DATA_NEESA              = 3,
    DATA_AHRIOK             = 4,
    DATA_MAKOGG             = 5,
    DATA_OHSIR              = 6,
    DATA_SKULLOC            = 7,
    DATA_ZOGGOSH            = 8,
    DATA_KORAMAR            = 9,
};

enum InstanceActions
{
    ACTION_GAUNTLET_1 = 1,
    ACTION_GAUNTLET_2,
    ACTION_GAUNTLET_3,
    ACTION_BOMBARD_GAUNTLET,
    ACTION_GAUNTLET_END,
    ACTION_OSHIR_INTRO,
    ACTION_RELEASE_ENFORCERS,
    ACTION_ENGAGE_ENFORCERS,
};

enum CreatureIds
{
    // Bosses
    BOSS_SKULLOC                    = 83612,
    BOSS_KORAMAR                    = 83613,
    BOSS_ZOGGOSH                    = 83616,

    BOSS_FLESHRENDER_NOKGAR         = 81305,
    BOSS_DREADFANG                  = 81297,

    NPC_ABILITY_SEQUENCER           = 82184,
    BOSS_NEESA_NOX                  = 80808,
    BOSS_MAKOGG_EMBERBLADE          = 80805,
    BOSS_AHRIOK_DUGRU               = 80816,

    // Generic npc's

    NPC_GROMKAR_FLAMESLINGER        = 81279,

    NPC_BACKDRAFT                   = 84464,
    NPC_BLACKHANDS_MIGHT_TURRET     = 84215,
    NPC_CANNON_1                    = 84109,
    NPC_CANNON_2                    = 84030,

    NPC_ENGINE                      = 83673,
    NPC_TRAIN_1                     = 83747,
    NPC_TRAIN_2                     = 83671,
    NPC_FLATBED                     = 83676,
    NPC_GUNCAR                      = 83682,
    NPC_TROOP_TRANSPORT             = 83778,
    NPC_TROOP_TRANSPORT_ENFORCERS   = 83672,
    NPC_OGRON_LABORER_TRAIN         = 83775,
    NPC_FLAMESLINGER_TRAIN          = 83776,
    NPC_IRONHOOF_PACKBEASR_TRAIN    = 83777,
};

enum EncounterCredits
{
    CREDIT_FLESHRENDER_NOKGAR   = 1749,
    CREDIT_GRIMRAIL_ENFORCERS   = 1748,
    CREDIT_OSHIR                = 1750,
    CREDIT_SKULLOC              = 1754,
};


template<class AI>
CreatureAI* GetIronDocksAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(IronDocksScriptName))
                return new AI(creature);
    return NULL;
}

#endif // IRON_DOCKS_H_
