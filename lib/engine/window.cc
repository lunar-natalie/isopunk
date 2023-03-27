// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file window.cc
/// @brief Window wrapper implementation.

#include <isopunk/engine/window.h>

#include <cstddef>
#include <cstdint>
#include <string>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/utils.h>

using namespace isopunk;

Window::Window(const std::string& title, uint32_t width, uint32_t height,
               SDL_WindowFlags flags)
    : extent{width, height}
{
    data = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, extent.width,
                            extent.height, flags);
    sdl_assert(data != NULL);
}

Window::~Window() noexcept
{
    SDL_DestroyWindow(data);
}
