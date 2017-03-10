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
#ifndef DEF_BLOODMAUL_SLAG_MINES_H
#define DEF_BLOODMAUL_SLAG_MINES_H

#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

enum DataTypes
{
    DATA_ROLTALL            = 0,
    DATA_CRUSHTO            = 1,
    DATA_GUGROKK            = 3,

    DATA_MAX_ENCOUNTERS     = 4,
};

enum Creatures
{
    // Boss
    BOSS_ROLTALL            = 86223,
    BOSS_CRUSHTO            = 86222,
    BOSS_GUGROKK            = 86224,
};

#define BloodmaulSlagScriptName "instance_bloodmaul_slag_mines"

template<typename AI, typename T>
AI* GetBloodmaulSlagAI(T* source)
{
    return GetInstanceAI<AI, T>(source, BloodmaulSlagScriptName);
}

#endif
