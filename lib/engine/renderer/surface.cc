// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file surface.cc
/// @brief Vulkan surface management.

#include <isopunk/engine/renderer.h>

#include <memory>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_structs.hpp>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/utils.h>
#include <isopunk/engine/window.h>

using namespace isopunk;

vkptr::SurfaceKHR Renderer::create_surface(WindowPtr&       wnd,
                                           vkptr::Instance& inst)
{
    VkSurfaceKHR s_data;
    sdl_assert(SDL_Vulkan_CreateSurface(
        wnd->data, static_cast<VkInstance>(**inst), &s_data));
    return std::make_unique<vkr::SurfaceKHR>(*inst.get(), s_data);
}
