// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file run.cc
/// @brief Runtime event handler.

#include <isopunk/engine.h>

#include <SDL2/SDL.h>

using namespace isopunk;

void Engine::start()
{
    SDL_Event e;
    bool      should_exit = false;

    while (!should_exit) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                should_exit = true;
                break;
            }
        }

        draw();
    }
}
