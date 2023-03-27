// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file surface.cc
/// @brief Vulkan surface creation.

#include <isopunk/engine.h>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/utils.h>

using namespace isopunk;

void Engine::vk_create_surface()
{
    sdl_assert(SDL_Vulkan_CreateSurface(
        window->data, static_cast<VkInstance>(vk_instance),
        reinterpret_cast<VkSurfaceKHR*>(&vk_surface)));
}
