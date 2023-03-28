// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file instance.cc
/// @brief Vulkan instance creation.

#include <isopunk/engine.h>

#include <cstdint>
#include <stdexcept>
#include <vector>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/utils.h>
#include <isopunk/version.h>

using namespace isopunk;

void Engine::vk_get_instance_extensions()
{
    // Enumerate extensions.
    unsigned int extension_count;
    sdl_assert(SDL_Vulkan_GetInstanceExtensions(window->data, &extension_count,
                                                nullptr));

    vk_extensions = std::vector<const char*>(extension_count);

    // Get names.
    sdl_assert(SDL_Vulkan_GetInstanceExtensions(window->data, &extension_count,
                                                vk_extensions.data()));
}

void Engine::vk_create_instance()
{
    vk::ApplicationInfo app_info{
        .pApplicationName = config.application_name.c_str(),
        .applicationVersion = config.application_version.vk_make_api_version(),
        .pEngineName = ENGINE_NAME,
        .engineVersion = ENGINE_VERSION.vk_make_api_version(),
        .apiVersion = VK_API_VERSION_1_0};

    vk::InstanceCreateInfo create_info{
        .pApplicationInfo = &app_info,
        .enabledLayerCount = static_cast<std::uint32_t>(vk_layers.size()),
        .ppEnabledLayerNames = vk_layers.data(),
        .enabledExtensionCount =
            static_cast<std::uint32_t>(vk_extensions.size()),
        .ppEnabledExtensionNames = vk_extensions.data()};

    try {
        vk_instance = vk::createInstance(create_info);
    }
    catch (vk::SystemError& e) {
        throw std::runtime_error(e.what());
    }
}
