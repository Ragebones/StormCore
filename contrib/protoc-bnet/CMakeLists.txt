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

cmake_minimum_required(VERSION 3.0)
project(protoc_bnet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Protobuf REQUIRED)

file(GLOB_RECURSE SOURCE_PROTOBUF_CPP google/protobuf/*.cc)

set(SOURCE_FILES
  main.cpp
  BnetCodeGenerator.cpp
  BnetFileGenerator.cpp
  BnetServiceGenerator.cpp
  method_options.pb.cc
  service_options.pb.cc
  ${SOURCE_PROTOBUF_CPP})

include_directories(${CMAKE_SOURCE_DIR} ${PROTOBUF_INCLUDE_DIRS})

add_executable(protoc-gen-bnet ${SOURCE_FILES})

target_link_libraries(protoc-gen-bnet ${PROTOBUF_PROTOC_LIBRARIES} ${PROTOBUF_LIBRARIES})

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

add_custom_target(install_plugin
  make install
  DEPENDS protoc-gen-bnet
  COMMENT "Installing protoc_bnet")

install(TARGETS protoc-gen-bnet DESTINATION bin)
