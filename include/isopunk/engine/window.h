// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file window.h
/// @brief Window wrapper utility header.

#ifndef ISOPUNK_ENGINE_WINDOW_H
#define ISOPUNK_ENGINE_WINDOW_H

#include <cstdint>
#include <memory>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.hpp>

namespace isopunk {

/// @brief Graphical window.
///
/// Wraps the SDL window type.
struct Window {
    SDL_Window*  data;
    vk::Extent2D extent;

    /// @brief Creates a new window.
    ///
    /// @param title Title text.
    /// @param w Initial width.
    /// @param h Initial height.
    /// @param flags SDL window creation flags.
    Window(char const*   title,
           std::uint32_t w,
           std::uint32_t h,
           Uint32        flags = SDL_WINDOW_VULKAN);

    ~Window() noexcept;
};

typedef std::unique_ptr<Window> WindowPtr;

} // namespace isopunk

#endif // ISOPUNK_ENGINE_WINDOW_H
