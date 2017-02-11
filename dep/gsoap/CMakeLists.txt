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

file(GLOB sources *.cpp *.h)

add_library(gsoap STATIC ${sources})

set_target_properties(gsoap PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(gsoap
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(gsoap
  PUBLIC
    -DWITH_OPENSSL)

target_link_libraries(gsoap
  PUBLIC
    openssl)

set_target_properties(gsoap
    PROPERTIES
      FOLDER
        "dep")

if (MSVC)
  # Little fix for MSVC / Windows platforms
  target_compile_definitions(gsoap
    PRIVATE
      -D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES=0)
endif()
