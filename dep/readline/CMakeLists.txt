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

if( UNIX )
  # find Readline (terminal input library) includes and library
  #
  # READLINE_INCLUDE_DIR - where the directory containing the READLINE headers can be found
  # READLINE_LIBRARY     - full path to the READLINE library
  find_path(READLINE_INCLUDE_DIR readline/readline.h)
  find_library(READLINE_LIBRARY NAMES readline)

  message(STATUS "Found Readline library: ${READLINE_LIBRARY}")
  message(STATUS "Include dir is: ${READLINE_INCLUDE_DIR}")

  if (NOT READLINE_INCLUDE_DIR OR NOT READLINE_LIBRARY)
    message(FATAL_ERROR "** Readline library not found!\n** Your distro may provide a binary for Readline e.g. for ubuntu try apt-get install libreadline5-dev")
  endif ()

  add_library(readline SHARED IMPORTED GLOBAL)

  set_target_properties(readline
    PROPERTIES
      IMPORTED_LOCATION
        "${READLINE_LIBRARY}"
      INTERFACE_INCLUDE_DIRECTORIES
        "${READLINE_INCLUDE_DIR}")

else()
  # Provide a dummy target
  add_library(readline INTERFACE)
endif()
