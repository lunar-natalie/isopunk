## Documentation build configuration.

set(DOXYFILE "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
set(DOXYFILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
set(DOXYGEN_COMMAND_LINE "\"${DOXYGEN_EXECUTABLE}\" ARGS \"${DOXYFILE}\"")
set(DOXYGEN_ROOT_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/out")

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
file(GLOB_RECURSE INCLUDE_FILES
  "${INCLUDE_DIR}/*.h"
)

file(GLOB SRC_GLOB "${CMAKE_SOURCE_DIR}/src/*")
foreach(file ${SRC_GLOB})
  if(IS_DIRECTORY "${file}")
    list(APPEND SRC_DIRS "${file}")
  endif()
endforeach()
file(GLOB_RECURSE SRC_FILES
  "${CMAKE_SOURCE_DIR}/src/*.h"
)

file(GLOB AUX_FILES
  "${CMAKE_SOURCE_DIR}/*.md"
)

if(IsoPunk_BUILD_DOCS_AUX)
  set(DOXYGEN_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md")
endif()

macro(add_doxygen_command file_list output_dir)
  if(NOT(file_list STREQUAL "") AND NOT(output_dir STREQUAL ""))
    string(REPLACE ";" " " files "${file_list}")
    string(APPEND DOXYGEN_COMMANDS
      "run_doxygen(\"${files}\" \"${output_dir}\")\n")
  endif()
endmacro()

if(IsoPunk_BUILD_DOCS_COMB)
  if(IsoPunk_BUILD_DOCS_INCLUDE)
    list(APPEND DOXYGEN_SOURCE_FILES "${INCLUDE_FILES}")
    list(APPEND DOXYGEN_PATH_LIST "${INCLUDE_DIR}")
  endif()
  if(IsoPunk_BUILD_DOCS_SRC)
    list(APPEND DOXYGEN_SOURCE_FILES "${SRC_FILES}")
    list(APPEND DOXYGEN_PATH_LIST ${SRC_DIRS})
  endif()
  if(IsoPunk_BUILD_DOCS_AUX)
    list(APPEND DOXYGEN_SOURCE_FILES "${AUX_FILES}")
  endif()
  if(DOXYGEN_SOURCE_FILES)
    add_doxygen_command("${DOXYGEN_SOURCE_FILES}"
      "${DOXYGEN_ROOT_OUTPUT_DIRECTORY}")
  endif()
else()
  if(IsoPunk_BUILD_DOCS_INCLUDE)
    add_doxygen_command("${INCLUDE_FILES}"
      "${DOXYGEN_ROOT_OUTPUT_DIRECTORY}/include")
    list(APPEND DOXYGEN_PATH_LIST "${INCLUDE_DIR}")
  endif()
  if(IsoPunk_BUILD_DOCS_SRC)
    add_doxygen_command("${SRC_FILES}"
      "${DOXYGEN_ROOT_OUTPUT_DIRECTORY}/src")
    list(APPEND DOXYGEN_PATH_LIST ${SRC_DIRS})
  endif()
  if(IsoPunk_BUILD_DOCS_AUX)
    add_doxygen_command("${AUX_FILES}"
      "${DOXYGEN_ROOT_OUTPUT_DIRECTORY}/project")
  endif()
endif()

string(REPLACE ";" " " DOXYGEN_STRIP_FROM_INC_PATH "${DOXYGEN_PATH_LIST}")

if(IsoPunk_ENABLE_STYLED_DOCS)
  include(FetchContent)

  FetchContent_Declare(doxygen-awesome-css
    GIT_REPOSITORY "https://github.com/jothepro/doxygen-awesome-css.git"
    GIT_TAG a7f7891706c656903326f79baf74beb2b711688d # release v2.2.0
  )

  FetchContent_MakeAvailable(doxygen-awesome-css)

  if(doxygen-awesome-css_POPULATED)
    set(DOXYGEN_STYLESHEET
      "${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome.css")

    string(REPLACE "." ";" VERSION_COMPONENTS "${DOXYGEN_VERSION}")
    list(LENGTH VERSION_COMPONENTS N_VERSION_COMPONENTS)
    if(N_VERSION_COMPONENTS GREATER_EQUAL 3)
      list(GET VERSION_COMPONENTS 0 MAJOR)
      list(GET VERSION_COMPONENTS 1 MINOR)
      list(GET VERSION_COMPONENTS 2 PATCH)
      if(MAJOR GREATER_EQUAL 1 AND MINOR GREATER_EQUAL 9
          AND PATCH GREATER_EQUAL 5)
        set(DOXYGEN_NEW True)
      endif()
    else()
      set(DOXYGEN_NEW False)
    endif()

    if(EXISTS "${DOXYGEN_STYLESHEET}")
      set(DOXYGEN_STYLE_CONFIG "\
GENERATE_TREEVIEW = YES
DISABLE_INDEX = NO
HTML_EXTRA_STYLESHEET = ${DOXYGEN_STYLESHEET}\
")
      if(DOXYGEN_NEW)
        set(DOXYGEN_STYLE_CONFIG "\
${DOXYGEN_STYLE_CONFIG}
FULL_SIDEBAR = NO
HTML_COLORSTYLE = LIGHT\
")
      endif()
    else()
     message("Failed to find Doxygen stylesheet. Using default styles")
    endif()
  else()
    message("Failed to retrieve Doxygen stylesheet repository. Using default styles")
  endif()
endif()

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/GenerateDocs.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/GenerateDocs.cmake"
  @ONLY)

add_custom_target(Docs ALL
  COMMAND
    "${CMAKE_COMMAND}"
      -P "${CMAKE_CURRENT_BINARY_DIR}/cmake/GenerateDocs.cmake"
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Generating documentation"
  VERBATIM)
