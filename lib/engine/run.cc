// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file run.cc
/// @brief Engine runtime loop.

#include <isopunk/engine.h>

#include <SDL2/SDL.h>

using namespace isopunk;

void Engine::run()
{
    SDL_Event e;
    bool should_exit = false;

    // Main loop.
    while (!should_exit) {
        // Process events.
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                should_exit = true;
                break;
            }
        }

        // Render.
        draw();
    }
}