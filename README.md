<p align="center">
  <img src="https://github.com/lunar-natalie/isopunk/raw/main/docs/assets/banner.png"
    alt="IsoPunk" width="1000"><br>
  <br>
  <img src="https://github.com/lunar-natalie/isopunk/raw/main/docs/assets/tools.png"
    alt="Tools" width="500"><br>
  <br>
  <a href="https://github.com/lunar-natalie/isopunk/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/lunar-natalie/isopunk"
      alt="License">
  </a>
  <a href="https://github.com/lunar-natalie/isopunk/actions/workflows/ci.yaml">
    <img src="https://github.com/lunar-natalie/isopunk/actions/workflows/ci.yaml/badge.svg?event=push"
      alt="CI">
  </a>
  <a href="https://github.com/lunar-natalie/isopunk/actions/workflows/docs.yaml">
    <img src="https://github.com/lunar-natalie/isopunk/actions/workflows/docs.yaml/badge.svg?event=push"
      alt="Documentation">
  </a><br>
  <br>
  <b>IsoPunk</b><br>
  <br>
  <a href="https://lunar-natalie.github.io/isopunk">Docs</a> |
    <a href="https://github.com/lunar-natalie/isopunk">GitHub</a><br>
  <br>
  <i>// Under Construction //</i><br>
  <br>
  A cross-platform isometric turn-based strategy game with a cyberpunk theme.
    <br>
  <br>
</p>

# Supported platforms

- Linux
- Windows 7 or newer (**TODO**)
- macOS 10.11 or newer (**TODO**)

# Dependencies

## Runtime environment

- Vulkan 1.0.24 or newer implementation
- Wayland or X11 (Linux)

**TODO**: Package

## Development environment

- C++20 toolchain
- CMake 3.21 or newer
- Boost
- SDL2
- GLM
- Vulkan 1.0.24 or newer SDK
- `glslc`
- `glslang-validator`

**Optional**

- Doxygen
- ClangFormat
- Cppcheck
- GDB

**TODO**: Manage dependencies

# Development

## Using Visual Studio Code

- Install the recommended workspace extensions when prompted, or run the
  `Extensions: Show Recommended Extensions` command and click the
  `Install Workspace Recommended Extensions` button in the sidebar.
- Configure the workspace for CMake when prompted, or run the `CMake: Configure`
  command. Select `all` as the build target.

The provided commands can be run from the Command Palette (default shortcut:
`Ctrl/Cmd+Shift+P`).

**Build targets**

- `Tasks: Run Build Task`
  - Default shortcut: `Ctrl/Cmd+Shift+B`

**Run the game**

- `CMake: Run Without Debugging`
  - Default shortcut: `Shift+F5`

**Debug the game**

- `CMake: Debug`
  - Default shortcut: `Ctrl/Cmd+F5`

**Run tests**

- `CMake: Run Tests`

## Standalone (using POSIX sh or compatible)

**Configure**

- Debug build type
  ```shell
  mkdir -p build && \
  cmake -DCMAKE_BUILD_TYPE=Debug -S. -Bbuild
  ```
- Release build type
  ```shell
  mkdir -p build && \
  cmake -S. -Bbuild
  ```

**Build**

```shell
cmake --build build
```

**Run**

```shell
build/src/game/isopunk
```

# ipkengine and documentation

The IsoPunk game engine, `ipkengine`, is exported as a library using CMake and
can be used to build applications externally. See the [documentation][www-docs]
for its usage.

# Project structure

## Source directories

- `include` - Headers, stored in the project subdirectory. C++20 modules are not
  used in this project due to the lack of support for external use.
- `lib` - Library source code, split into subdirectories corresponding to the
  name of each library target.
- `src` - Executable source code, split into subdirectories corresponding to the
  name of each executable target.
- `tests` - Unit tests, split into subdirectories corresponding to the name of
  each tested component.

# Source files

The source files comprising each target can be found and modified in the calls
to `add_library`, `add_executable` and `target_sources` within the
`CMakeLists.txt` file of each processed source directory.

## Filenames

Source and header filenames are written in snake case. CMake filenames are
written in Pascal case.

**Source file extensions**
| | C++ Source | C++ Header |
|---------------|-------------|-------------|
| **Extension** |`.cc` |`.h` |

## File comments

Note: Text surrounded by braces in the format guides should be substituted with an appropriate value.

**C++**

Documented source files should start with a comment in the following format:

```
// {PROJECT_COMPONENT}
// Copyright (c) {YEAR} {NAME} <{EMAIL}>
//
// SPDX-License-Identifier: {LICENSE_IDENTIFIER}

/// @file {FILENAME}
/// @brief {BRIEF_DESCRIPTION}
```

Non-documented source files should start with a comment in the following
format:

```
// {PROJECT_COMPONENT}
// Copyright (c) {YEAR} {NAME} <{EMAIL}>
//
// SPDX-License-Identifier: {LICENSE_IDENTIFIER}
//
// BRIEF_DESCRIPTION
```

**CMake**

Files should start in the format `## {SHORT_DESCRIPTION}`.

## Documentation comments

The public API is documented using Doxygen comments, denoted by a `///` in the
source code. Private identifiers may also be documented in this way.

## Code style

Each C/C++ header should be encapsulated with an include guard using an
identifier with the name of the source file in the form
`DIR1_DIR2_DIRN_FILENAME_H`. `#pragma once` is not used due to portability
issues.

Code should be formatted according to the ClangFormat rules. To enforce this
style, installing ClangFormat is recommended as it is run at build time when
available.

## File formatting

All project files should be formatted according to the EditorConfig rules. Many
editors support the EditorConfig system.

# License

Copyright (c) 2023 Natalie Wiggins.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.

See the `LICENSE` file for more information.

[www-docs]: https://lunar-natalie.github.io/isopunk
