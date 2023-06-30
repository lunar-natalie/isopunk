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
#include "options.h"
#include <isopunk/version.h>

using namespace isopunk;

int main(int argc, char* argv[])
try {
    // Parse program options
    Options opt(argc, argv);
    opt.desc->add_options()("help", "display this help and exit")(
        "version", "output version information and exit");
    auto vm = opt.parse_args();

    if (vm->count("help")) {
        std::cout << *opt.desc << "\n";
        return EXIT_FAILURE;
    }
    else if (vm->count("version")) {
        std::cout << "IsoPunk (ipkengine) " << ENGINE_VERSION.to_string()
                  << ")\n"
                  << "Copyright (C) " << ENGINE_YEAR
                  << " The IsoPunk Project Authors.\n"
                  << "License GPLv3+: GNU GPL version 3 or later "
                     "<https://gnu.org/licenses/gpl.html>.\n"
                  << "This is free software: you are free to change and "
                     "redistribute it.\n"
                  << "There is NO WARRANTY, to the extent permitted by law.\n"
                  << "\n"
                  << "Written by Natalie Wiggins\n";
        return EXIT_SUCCESS;
    }

    // Initialize engine and start the game
    Game game;
    game.start();

    return EXIT_SUCCESS;
}
catch (std::runtime_error& e) {
    // Terminate if engine throws a fatal error
    std::cerr << e.what() << '\n';

    return EXIT_FAILURE;
}
