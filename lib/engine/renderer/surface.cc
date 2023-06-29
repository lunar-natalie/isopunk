// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file surface.cc
/// @brief Vulkan surface management.

#include <isopunk/engine/renderer.h>

#include <memory>
#include <utility>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan_raii.hpp>
#include <vulkan/vulkan_structs.hpp>

#include <isopunk/engine/defs.h>
#include <isopunk/engine/utils.h>
#include <isopunk/engine/window.h>

using namespace isopunk;

vkptr::SurfaceKHR Renderer::create_surface(Window& window,
                                           vkptr::Instance& instance)
{
    VkSurfaceKHR surface_data;
    sdl_assert(SDL_Vulkan_CreateSurface(
        window.data, static_cast<VkInstance>(**instance), &surface_data));
    return std::make_unique<vkr::SurfaceKHR>(*instance.get(), surface_data);
}
