## Build configuration for library tests.

add_executable(TestLibs
  engine.cc
  module.cc
)

set_target_properties(TestLibs
  PROPERTIES
    OUTPUT_NAME test-libs
    CXX_STANDARD ${IsoPunk_CXX_STANDARD}
    CXX_STANDARD_REQUIRED ON)

target_include_directories(TestLibs
  PRIVATE
    ${IsoPunk_INCLUDE_DIRS}

    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(TestLibs
  PRIVATE
    Engine

    Boost::unit_test_framework
)

add_test(NAME Libraries
  COMMAND TestLibs --no_color_output)
