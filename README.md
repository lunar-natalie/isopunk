<p style="text-align: center">
  <img src="https://github.com/lunar-natalie/isopunk/docs/assets/banner.png"
    alt="IsoPunk" style="width: 100vw"><br>
  <img src="https://github.com/lunar-natalie/isopunk/docs/assets/tools.png"
    alt="Tools" style="width: 50vw"><br>
  <br>
  <img src="https://github.com/lunar-natalie/isopunk/actions/workflows/ci.yaml/badge.svg"
    alt="CI"><br>
  <br>
  <b>IsoPunk</b><br>
  <br>
  // Under Construction //<br>
  <br>
  A cross-platform isometric turn-based strategy game with a cyberpunk theme.<br><br>
</p>

## Table of contents

* [Table of contents](#table-of-contents)
* [Supported platforms](#supported-platforms)
* [Dependencies](#dependencies)
  * [Runtime](#runtime)
  * [Development](#development)
* [Development](#development-1)
  * [Using VS Code](#using-vs-code)
  * [Standalone](#standalone)
* [ipkengine](#ipkengine)
* [Structure](#structure)
  * [Source directories](#source-directories)
  * [Filenames](#filenames)
  * [File comments](#file-comments)
  * [Documentation comments](#documentation-comments)
  * [Code style](#code-style)
  * [File formatting](#file-formatting)
* [License](#license)

## Supported platforms

* Linux
* Windows 7 or newer (**TODO**)
* macOS 10.11 or newer (**TODO**)

## Dependencies

### Runtime

* Vulkan 1.0 or newer implementation
* Wayland or X11 (Linux)

**TODO**: Package

### Development

* C++20 toolchain
* CMake 3.21 or newer
* Boost
* SDL2
* GLM
* Vulkan 1.0 or newer headers, including `vulkan-hpp`

Optional:
* Doxygen
* ClangFormat
* Cppcheck
* GDB

**TODO**: Manage

## Development

### Using VS Code

* Install the recommended workspace extensions when prompted, or run the
  `Extensions: Show Recommended Extensions` command and click the
  `Install Workspace Recommended Extensions` button in the sidebar.
* Configure the workspace for CMake when prompted, or run the `CMake: Configure`
  command. Select `all` as the build target.

The provided commands can be run from the Command Palette (default shortcut:
`Ctrl/Cmd+Shift+P`).

Build:
* `Tasks: Run Build Task`
  * Default shortcut: `Ctrl/Cmd+Shift+B`

Run game:
* `CMake: Run Without Debugging`
  * Default shortcut: `Shift+F5`

Debug game:
* `CMake: Debug`
  * Default shortcut: `Ctrl/Cmd+F5`

Test:
* `CMake: Run Tests`

### Standalone

Configure:
* Debug target
  ```shell
  mkdir -p build && \
  cmake -DCMAKE_BUILD_TYPE=Debug -S. -Bbuild
  ```
* Release target
  ```shell
  mkdir -p build && \
  cmake -S. -Bbuild
  ```

Build:
```shell
cmake --build build
```

Run:
```shell
build/src/game/isopunk
```

## ipkengine

The IsoPunk game engine, `ipkengine`, is exported as a library using CMake and
can be used to build applications externally. See the code documentation for
its usage.

**TODO**: Publish docs

## Structure

### Source directories

* `include` - Headers, stored in the project subdirectory. C++20 modules are not
  used in this project due to the lack of support for external use.
* `lib` - Library source code, split into subdirectories corresponding to the
  name of each library target.
* `src` - Executable source code, split into subdirectories corresponding to the
  name of each executable target.
* `tests` - Unit tests, split into subdirectories corresponding to the name of
  each tested component.

### Filenames

Source and header filenames are written in snake case. CMake filenames are
written in Pascal case.

**Source file extensions**
|               | C++ Source  | C++ Header  |
|---------------|-------------|-------------|
| **Extension** |`.cc`        |`.h`         |

### File comments

**C++**
* Files should be prefixed with a short description followed by an empty comment
  before the following block, unless the file declares or implements exactly one
  documented abstraction, in which case the description is not required.
```c++
// This (header/file) is part of COMPONENT.
//
// Copyright (c) YEAR AUTHOR <EMAIL>
//
// SPDX-License-Identifier: IDENTIFIER
```
**CMake**
* Files should start with `## A SHORT DESCRIPTION`.

### Documentation comments

The public API is documented using Doxygen comments, denoted by a `///` in the
source code. Private identifiers may also be documented in this way.

### Code style

Each C/C++ header should be encapsulated with an include guard using an
identifier with the name of the source file in the form
`DIR1_DIR2_DIRN_FILENAME_H`. `#pragma once` is not used due to portability
issues.

Code should be formatted according to the ClangFormat rules. To enforce this
style, installing ClangFormat is recommended as it is run at build time when
available.

### File formatting

All project files should be formatted according to the EditorConfig rules. Many
editors support the EditorConfig system.

## License

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
