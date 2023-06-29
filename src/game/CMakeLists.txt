## Game build configuration.

add_executable(Game
  "game.cc"
  "game.h"
  "main.cc"
)

set_target_properties(Game
  PROPERTIES
    OUTPUT_NAME isopunk
    CXX_STANDARD ${IsoPunk_CXX_STANDARD}
    CXX_STANDARD_REQUIRED ON)

target_include_directories(Game
  PRIVATE
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(Game
  PRIVATE
    Engine

    Boost::program_options
)

install(TARGETS Game
  DESTINATION "${CMAKE_INSTALL_BINDIR}")
