// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file window.h
/// @brief Window wrapper.

#ifndef ISOPUNK_ENGINE_WINDOW_H
#define ISOPUNK_ENGINE_WINDOW_H

#include <cstdint>
#include <string>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.hpp>

namespace isopunk {

/// @brief Graphical window wrapper.
struct Window {
    /// @brief Creates a new window, initializing the object's SDL window and
    /// extent (size).
    ///
    /// @param title String to be used for the window title.
    /// @param width Initial width of the window, in pixels.
    /// @param height Initial height of the window, in pixels.
    /// @param flags Window creation flags to pass to SDL.
    Window(const std::string& title, std::uint32_t width, std::uint32_t height,
           Uint32 flags = SDL_WINDOW_VULKAN);

    /// @brief Destroys the window and its SDL object.
    ~Window() noexcept;

    /// @brief SDL window data.
    SDL_Window* data;

    /// @brief Size in pixels.
    vk::Extent2D extent;
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_WINDOW_H
