/*
 * Copyright (C) 2016-2017 DeathCore <http://www.noffearrdeathproject.org/>
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

#ifndef CONNECTION_PATCHER_CONSTANTS_BINARYTYPES_HPP
#define CONNECTION_PATCHER_CONSTANTS_BINARYTYPES_HPP

#include <cstdint>

namespace Connection_Patcher
{
    namespace Constants
    {
        enum class BinaryTypes : uint32_t
        {
            Pe32   = 0x0000014C,
            Pe64   = 0x00008664,
            Mach64 = 0xFEEDFACF
        };
    }
}

#endif
