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

set(HEADER_FILES
  Helper.hpp
  Patcher.hpp
  Constants/BinaryTypes.hpp
  Patches/Common.hpp
  Patches/Mac.hpp
  Patches/Windows.hpp
  Patterns/Common.hpp
  Patterns/Mac.hpp
  Patterns/Windows.hpp
)

set(SRC_FILES
  Helper.cpp
  Patcher.cpp
  Program.cpp
)

if (WIN32)
  list(APPEND SRC_FILES ${sources_windows})
endif()

add_executable(connection_patcher ${HEADER_FILES} ${SRC_FILES})

target_link_libraries(connection_patcher
  PUBLIC
    common
)

if (UNIX)
  install(TARGETS connection_patcher DESTINATION bin)
elseif (WIN32)
  install(TARGETS connection_patcher DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif ()
