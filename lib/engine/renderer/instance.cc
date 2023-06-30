// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file instance.cc
/// @brief Vulkan instance management.

#include <isopunk/engine/renderer.h>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_structs.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/rdef.h>
#include <isopunk/engine/utils.h>
#include <isopunk/engine/window.h>
#include <isopunk/version.h>

using namespace isopunk;

std::vector<const char*> Renderer::get_extensions(WindowPtr& wnd)
{
    std::vector<const char*> ret;
    unsigned int             count;

    // Enumerate extensions
    sdl_assert(SDL_Vulkan_GetInstanceExtensions(wnd->data, &count, nullptr));

    // Allocate
    ret = std::vector<const char*>(count);

    // Retrieve extension names
    sdl_assert(SDL_Vulkan_GetInstanceExtensions(wnd->data, &count, ret.data()));

    return ret;
}

vkptr::Instance Renderer::create_instance(EngineConfig const& config,
                                          vkr::Context&       ctx,
                                          WindowPtr&          wnd)
{
    vk::ApplicationInfo app_info{
        .pApplicationName   = config.app_name.c_str(),
        .applicationVersion = config.app_version.mk_vk_api_version(),
        .pEngineName        = ENGINE_NAME,
        .engineVersion      = ENGINE_VERSION.mk_vk_api_version(),
        .apiVersion         = VK_API_VERSION_1_0};

    auto ext = get_extensions(wnd);

    try {
        return std::make_shared<vkr::Instance>(
            ctx,
            vk::InstanceCreateInfo{.pApplicationInfo = &app_info,
                                   .enabledExtensionCount =
                                       static_cast<uint32_t>(ext.size()),
                                   .ppEnabledExtensionNames = ext.data()});
    }
    catch (vk::SystemError& e) {
        throw std::runtime_error(e.what());
    }
}
