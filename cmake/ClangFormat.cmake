## ClangFormat CMake target.
## Formats all C++ code in the project.

find_program(CLANGFORMAT NAMES clang-format)

if(NOT (CLANGFORMAT STREQUAL "CLANGFORMAT-NOTFOUND"))
  add_custom_target(ClangFormat ALL
    COMMAND ${CLANGFORMAT} -i ${${PROJECT_NAME}_ALL_SOURCE_FILES})
endif()
