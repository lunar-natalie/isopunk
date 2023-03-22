// Vulkan management.
//
// This file is part of the ipkengine library.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <isopunk/engine.h>

#include <cstdint>
#include <stdexcept>
#include <vector>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/utils.h>
#include <isopunk/version.h>

using namespace isopunk;

void Engine::vk_init()
{
    // TODO
    vk_get_instance_extensions();
    vk_create_instance();
}

void Engine::vk_get_instance_extensions()
{
    // Enumerate extensions.
    unsigned int extension_count;
    sdl_assert(
        SDL_Vulkan_GetInstanceExtensions(window, &extension_count, nullptr));

    extensions = std::vector<const char*>(extension_count);

    // Get names.
    sdl_assert(SDL_Vulkan_GetInstanceExtensions(window, &extension_count,
                                                extensions.data()));
}

void Engine::vk_create_instance()
{
    vk::ApplicationInfo app_info{
        .pApplicationName = config.application_name.c_str(),
        .applicationVersion = config.application_version.vk_make_api_version(),
        .pEngineName = "ipkengine",
        .engineVersion = config::ENGINE_VERSION.vk_make_api_version(),
        .apiVersion = VK_API_VERSION_1_0};

    vk::InstanceCreateInfo create_info{
        .pApplicationInfo = &app_info,
        .enabledLayerCount = static_cast<uint32_t>(layers.size()),
        .ppEnabledLayerNames = layers.data(),
        .enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
        .ppEnabledExtensionNames = extensions.data()};

    try {
        vk_instance = vk::createInstance(create_info);
    }
    catch (vk::SystemError& e) {
        throw std::runtime_error(e.what());
    }
}

void Engine::vk_deinit() const noexcept
{
    vk_instance.destroy();
}
