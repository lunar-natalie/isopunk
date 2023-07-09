## Build configuration for includes.

set(IsoPunk_INCLUDE_DIRS
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")

configure_file(isopunk/version.h.in
  "${CMAKE_CURRENT_BINARY_DIR}/isopunk/version.h")

add_library(Headers INTERFACE)

target_sources(Headers PUBLIC FILE_SET HEADERS
  BASE_DIRS "${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}"
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/isopunk/version.h"
    "isopunk/engine.h"
    "isopunk/engine/config.h"
    "isopunk/engine/rdef.h"
    "isopunk/engine/renderer.h"
    "isopunk/engine/renderer/phys_device.h"
    "isopunk/engine/renderer/queues.h"
    "isopunk/engine/renderer/surface.h"
    "isopunk/engine/utils.h"
    "isopunk/engine/window.h"
)

set_target_properties(Headers
  PROPERTIES
    CXX_STANDARD ${IsoPunk_CXX_STANDARD}
    CXX_STANDARD_REQUIRED ON)

target_compile_definitions(Headers
  INTERFACE
    VULKAN_HPP_NO_CONSTRUCTORS)

target_include_directories(Headers
  INTERFACE
    ${IsoPunk_INCLUDE_DIRS}

    ${Vulkan_INCLUDE_DIRS}
)

target_link_libraries(Headers
  INTERFACE
    SDL2::SDL2
    Vulkan::Vulkan
)

if(IsoPunk_INSTALL_LIBS)
  install(TARGETS Headers
    EXPORT HeadersTargets
    FILE_SET HEADERS DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

  install(EXPORT HeadersTargets
    FILE HeadersTargets.cmake
    NAMESPACE IsoPunk
    DESTINATION "${IsoPunk_CMAKE_INSTALL_DIR}")
endif()
