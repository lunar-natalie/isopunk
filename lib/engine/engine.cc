// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file engine.cc
/// @brief Engine member definitions.

#include <isopunk/engine.h>

#include <memory>

#include <SDL2/SDL.h>

#include <isopunk/engine/renderer.h>
#include <isopunk/engine/utils.h>

using namespace isopunk;

Engine::Engine(EngineConfig config)
    : config{config}
{
    // Initialize SDL and create the main window.
    Uint32 sdl_flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    sdl_assert(SDL_Init(sdl_flags) == 0);
    window =
        std::make_unique<Window>(config.application_name.c_str(),
                                 config.window_width, config.window_height);
    renderer = std::make_unique<Renderer>(config);
}

Engine::~Engine() noexcept
{
    SDL_Quit();
}
