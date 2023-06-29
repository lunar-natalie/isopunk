// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file window.cc
/// @brief Window wrapper implementation.

#include <isopunk/engine/window.h>

#include <cstdint>

#include <SDL2/SDL.h>

#include <isopunk/engine/utils.h>

using namespace isopunk;

Window::Window(const char* title, std::uint32_t width, std::uint32_t height,
               Uint32 flags)
    : extent{width, height}
{
    data = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, extent.width,
                            extent.height, flags);
    sdl_assert(data != nullptr);
}

Window::~Window() noexcept
{
    SDL_DestroyWindow(data);
}
