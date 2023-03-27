// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file init.cc
/// @brief Engine initialization.

#include <isopunk/engine.h>

#include <SDL2/SDL.h>

#include <isopunk/engine/utils.h>

using namespace isopunk;

void Engine::init()
{
    // Initialize SDL and create the main window.
    Uint32 sdl_flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    sdl_assert(SDL_Init(sdl_flags) == 0);

    window = new Window(config.application_name, config.window_width,
                        config.window_height);

    // Load core Vulkan structures.
    vk_init();
}

void Engine::terminate() const noexcept
{
    // Deinitialize core Vulkan structures.
    vk_deinit();

    delete window;
}
