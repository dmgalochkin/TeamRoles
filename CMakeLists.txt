cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME TeamRoles)
project(${PROJECT_NAME})


set(application TApplication)
set(library TeamRolesLib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Config" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TeamRolesLib)

add_subdirectory(TeamRolesLib)
add_subdirectory(TApp)
add_subdirectory(gtest)
add_subdirectory(test)