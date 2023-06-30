// IsoPunk
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file main.cc
/// @brief Program entrypoint.

#include <cstdlib>

#include <iostream>
#include <stdexcept>

#include "game.h"

using namespace isopunk;

int main(int argc, char* argv[])
try {
    Game game;
    game.start();

    return EXIT_SUCCESS;
}
catch (std::runtime_error& e) {
    std::cerr << e.what() << '\n';

    return EXIT_FAILURE;
}
