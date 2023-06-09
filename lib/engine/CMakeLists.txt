## Engine build configuration.

add_library(Engine
  config.cc
  engine.cc
  renderer.cc
  runtime.cc
  vulkan.cc
)

set_target_properties(Engine
  PROPERTIES
    OUTPUT_NAME ipkengine
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
    CXX_STANDARD ${IsoPunk_CXX_STANDARD}
    CXX_STANDARD_REQUIRED ON)

target_link_libraries(Engine
  PUBLIC
    Headers

    glm::glm
    SDL2::SDL2main
)

if(IsoPunk_INSTALL_LIBS)
  install(TARGETS Engine
    EXPORT EngineTargets
    DESTINATION "${CMAKE_INSTALL_LIBDIR}")

  install(EXPORT EngineTargets
    FILE EngineTargets.cmake
    NAMESPACE IsoPunk
    DESTINATION "${IsoPunk_CMAKE_INSTALL_DIR}/engine")
endif()
