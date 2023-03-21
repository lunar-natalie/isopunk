// Program entrypoint.
//
// This file is part of IsoPunk.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <cstdlib>

#include <iostream>
#include <stdexcept>

#include "game.h"

using namespace isopunk;

int main(int argc, char* argv[])
try {
    // Create and start the game instance.
    Game game;
    game.start();

    return EXIT_SUCCESS;
}
catch (std::runtime_error& e) {
    // TODO: Logs

    std::cerr << e.what() << std::endl;

    // Terminate if a fatal exception is thrown by the game instance.
    return EXIT_FAILURE;
}
