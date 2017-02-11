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

include(CheckSymbolExists)
if (WIN32)
  check_symbol_exists(open io.h HAVE_OPEN)
else ()
  check_symbol_exists(open fcntl.h HAVE_OPEN)
endif ()

set(FMT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/fmt/format.h
  ${CMAKE_CURRENT_SOURCE_DIR}/fmt/format.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/fmt/ostream.h
  ${CMAKE_CURRENT_SOURCE_DIR}/fmt/ostream.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/fmt/time.h)

if (HAVE_OPEN)
  set(FMT_SOURCES ${FMT_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/fmt/posix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fmt/posix.cc)
endif()

add_library(fmt STATIC ${FMT_SOURCES})

target_include_directories(fmt
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(fmt
    PROPERTIES
      FOLDER
        "dep")
