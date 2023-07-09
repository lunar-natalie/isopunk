// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file window.cc
/// @brief SDL window wrapper implementation.

#include <isopunk/engine/window.h>

#include <cstdint>

#include <SDL2/SDL.h>

#include <isopunk/engine/utils.h>

using namespace isopunk;

Window::Window(char const*   title,
               std::uint32_t w,
               std::uint32_t h,
               Uint32        flags)
    : extent{w, h}
{
    data = SDL_CreateWindow(title,
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            extent.width,
                            extent.height,
                            flags);
    sdl_assert(data != nullptr);
}

Window::~Window() noexcept
{
    SDL_DestroyWindow(data);
}
