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
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/rdef.h>
#include <isopunk/engine/utils.h>
#include <isopunk/engine/window.h>
#include <isopunk/version.h>

using namespace isopunk;

std::vector<const char*>
Renderer::get_instance_extensions(WindowPtr& wnd, vkr::Context const& ctx)
{
    std::vector<const char*> exts;
    unsigned int             sdl_ext_count;

    // Enumerate Vulkan extensions supported by SDL
    sdl_assert(
        SDL_Vulkan_GetInstanceExtensions(wnd->data, &sdl_ext_count, nullptr));

    // Allocate
    exts = std::vector<const char*>(sdl_ext_count);

    // Retrieve extension names
    sdl_assert(SDL_Vulkan_GetInstanceExtensions(
        wnd->data, &sdl_ext_count, exts.data()));

    // Additional extensions
#ifndef NDEBUG
    exts.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif

    std::vector<vk::ExtensionProperties> props =
        ctx.enumerateInstanceExtensionProperties();

    auto prop_itr = std::find_if(
        props.begin(), props.end(), [](vk::ExtensionProperties const& p) {
            return strcmp(p.extensionName, VK_EXT_DEBUG_UTILS_EXTENSION_NAME)
                   == 0;
        });
    if (prop_itr == props.end()) {
        throw std::runtime_error(
            "Failed to find Vulkan "
            "extension " VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return exts;
}

vkptr::Instance Renderer::create_instance(EngineConfig const& config,
                                          WindowPtr&          wnd,
                                          vkr::Context&       ctx)
{
    vk::ApplicationInfo app_info{
        .pApplicationName   = config.app_name.c_str(),
        .applicationVersion = config.app_version.mk_vk_api_version(),
        .pEngineName        = ENGINE_NAME,
        .engineVersion      = ENGINE_VERSION.mk_vk_api_version(),
        .apiVersion         = VK_API_VERSION_1_0};

    auto exts = get_instance_extensions(wnd, ctx);

    try {
        return std::make_unique<vkr::Instance>(
            ctx,
            vk::InstanceCreateInfo{.pApplicationInfo = &app_info,
                                   .enabledExtensionCount =
                                       static_cast<std::uint32_t>(exts.size()),
                                   .ppEnabledExtensionNames = exts.data()});
    }
    catch (vk::SystemError& e) {
        throw std::runtime_error(e.what());
    }
}
