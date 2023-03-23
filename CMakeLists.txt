## Root build configuration for IsoPunk.

cmake_minimum_required(VERSION 3.23)

################################################################################
## Project initialization ######################################################
################################################################################

project(IsoPunk
  VERSION 0.1.0
  DESCRIPTION "Isometric turn-based strategy game"
  HOMEPAGE_URL "https://github.com/lunar-natalie/isopunk"
  LANGUAGES CXX)

################################################################################
## Options #####################################################################
################################################################################

if(CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug")
  set(IsoPunk_BUILD_DEBUG ON)
  set(IsoPunk_BUILD_RELEASE OFF)
else()
  set(IsoPunk_BUILD_DEBUG OFF)
  set(IsoPunk_BUILD_RELEASE ON)
endif()

option(IsoPunk_BUILD_DOCS "Enable documentation" OFF)
option(IsoPunk_BUILD_DOCS_AUX "Build auxiliary documentation" ON)
option(IsoPunk_BUILD_DOCS_COMB "Combine component documentation into a single directory" ON)
option(IsoPunk_BUILD_DOCS_INCLUDE "Build include documentation" ON)
option(IsoPunk_BUILD_DOCS_SRC "Build src documentation" OFF)
option(IsoPunk_BUILD_GAME "Build the game" ON)
option(IsoPunk_ENABLE_LIBS "Build libraries" ON)
option(IsoPunk_ENABLE_STYLED_DOCS "Enable custom CSS in HTML generated documentation" ON)
option(IsoPunk_ENABLE_TESTS "Enable unit tests" ${IsoPunk_BUILD_DEBUG})
option(IsoPunk_INSTALL_LIBS "Install libraries" ON)

################################################################################
## Dependencies ################################################################
################################################################################

# SDL
# Simple DirectMedia Layer for cross-platform media hardware access.
find_package(SDL2 REQUIRED)

# Vulkan
# Modern, high-performance, portable low level graphics API.
find_package(Vulkan 1.0.24 REQUIRED)

# Boost
# Portable multi-purpose C++ source libraries.
find_package(Boost
  COMPONENTS
    program_options     # Command-line and config-based option parsing
    unit_test_framework # Framework for unit testing project components
)

# GLM
# Mathematics library.
find_package(glm REQUIRED)

# Doxygen
# Documentation generator.
find_package(Doxygen)

# Git
# Used for obtaining documentation CSS.
find_package(Git)

################################################################################
## Optional components #########################################################
################################################################################

# Game
# Requries Boost program options.
if(IsoPunk_BUILD_GAME)
  if(NOT Boost_program_options_FOUND)
    set(IsoPunk_BUILD_GAME OFF)
    message("Boost program options library not found. Game build has been disabled.")
  endif()
endif()

# Unit tests
# Requires Boost unit test framework.
if(IsoPunk_ENABLE_TESTS)
  if(NOT Boost_unit_test_framework_FOUND)
    set(IsoPunk_ENABLE_TESTS OFF)
    message("Boost unit test framework not found. Unit tests are unavailable.")
  endif()
endif()

# Documentation
# Requires Doxygen, and Git if styles are enabled.
if(IsoPunk_BUILD_DOCS)
  if(NOT DOXYGEN_FOUND)
    set(IsoPunk_BUILD_DOCS OFF)
    message("Doxygen not found. Documentation generation is unavailable.")
  endif()
  if(NOT Git_FOUND)
    set(IsoPunk_ENABLE_STYLED_DOCS OFF)
    message("Git not found. Styled documentation is unavailable.")
  endif()
endif()

################################################################################
## Globals #####################################################################
################################################################################

# Project C++ language standard.
set(IsoPunk_CXX_STANDARD 20)

# Source directorhy for CMake files in the project scope.
set(IsoPunk_CMAKE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/cmake")

# Installation directories
include(GNUInstallDirs)

# Target installation directory for CMake files in the project scope.
set(IsoPunk_CMAKE_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/isopunk")

################################################################################
## Code tools ##################################################################
################################################################################

file(GLOB_RECURSE IsoPunk_ALL_SOURCE_FILES
  "${PROJECT_SOURCE_DIR}/include/*.h"
  "${PROJECT_SOURCE_DIR}/lib/*.cc"
  "${PROJECT_SOURCE_DIR}/lib/*.h"
  "${PROJECT_SOURCE_DIR}/src/*.cc"
  "${PROJECT_SOURCE_DIR}/src/*.h"
  "${PROJECT_SOURCE_DIR}/tests/*.cc"
  "${PROJECT_SOURCE_DIR}/tests/*.h"
)

include("${IsoPunk_CMAKE_SOURCE_DIR}/Cppcheck.cmake")
include("${IsoPunk_CMAKE_SOURCE_DIR}/ClangFormat.cmake")

################################################################################
## Project components ##########################################################
################################################################################

if(IsoPunk_ENABLE_LIBS)
  # Headers
  add_subdirectory(include)

  # Libraries
  add_subdirectory(lib)
endif()

# Executables
add_subdirectory(src)

# Tests
if(IsoPunk_ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# Documentation
if(IsoPunk_BUILD_DOCS)
  add_subdirectory(docs)
endif()

################################################################################
## Install and package configuration ###########################################
################################################################################

if(IsoPunk_INSTALL_LIBS)
  include("${IsoPunk_CMAKE_SOURCE_DIR}/GeneratePackage.cmake")
endif()
