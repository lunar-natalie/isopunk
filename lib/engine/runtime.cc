// Core engine runtime methods.
//
// This file is part of the ipkengine library.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <isopunk/engine.h>

#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include <isopunk/engine/utils.h>

using namespace isopunk;

void Engine::init()
{
    // Initialize SDL and create the main window.
    Uint32 sdl_flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    sdl_assert(SDL_Init(sdl_flags) == 0);

    SDL_WindowFlags window_flags = SDL_WINDOW_VULKAN;
    window = SDL_CreateWindow(config.application_name.c_str(),
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              window_extent.width, window_extent.height,
                              window_flags);

    sdl_assert(window != NULL);

    // Load core Vulkan structures.
    init_vk();
}

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

void Engine::terminate()
{
    SDL_DestroyWindow(window);
}
