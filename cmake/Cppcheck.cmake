## Cppcheck CMake target.
## Statically analyzes all C++ code in the project.

find_program(CPPCHECK NAMES cppcheck)

if(NOT (CPPCHECK STREQUAL "CPPCHECK-NOTFOUND"))
  add_custom_target(cppcheck ALL
    COMMAND ${CPPCHECK}
      --enable=warning,performance,portability,information,missingInclude
      --suppress=missingIncludeSystem
      --std=c++${${PROJECT_NAME}_CXX_STANDARD}
      --language=c++
      --library=std.cfg
      --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
      --verbose
      --quiet
      ${${PROJECT_NAME}_ALL_SOURCE_FILES})
endif()
