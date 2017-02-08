# Copyright (C) 2016-2017 DeathCore <http://www.noffearrdeathproject.org/>
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>.

if (NOT MYSQL_FOUND)
  message(FATAL_ERROR "MySQL wasn't found on your system but it's required to build the servers!")
endif()

add_library(mysql STATIC IMPORTED GLOBAL)

set_target_properties(mysql
  PROPERTIES
    IMPORTED_LOCATION
      "${MYSQL_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES
      "${MYSQL_INCLUDE_DIR}")
