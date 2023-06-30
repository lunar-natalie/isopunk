// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file engine.cc
/// @brief Engine member definitions.

#include <isopunk/engine.h>

#include <memory>

#include <SDL2/SDL.h>

#include <isopunk/engine/config.h>
#include <isopunk/engine/renderer.h>
#include <isopunk/engine/utils.h>

using namespace isopunk;

Engine::Engine(EngineConfig const conf)
    : conf{conf}
{
    sdl_assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0);

    wnd = std::make_unique<Window>(
        conf.app_name.c_str(), conf.window_width, conf.window_height);

    renderer = std::make_unique<Renderer>(conf, wnd);
}

Engine::~Engine() noexcept
{
    SDL_Quit();
}
