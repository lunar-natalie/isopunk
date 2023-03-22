// Vulkan management.
//
// This file is part of the ipkengine library.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <isopunk/engine.h>

#include <cstdint>
#include <vector>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/utils.h>
#include <isopunk/version.h>

using namespace isopunk;

void Engine::init_vk()
{
    // TODO
    vk_get_instance_extensions();
    vk_create_instance();
}

void Engine::vk_get_instance_extensions()
{
    unsigned int extension_count;
    sdl_assert(
        SDL_Vulkan_GetInstanceExtensions(window, &extension_count, nullptr));
    extensions = std::vector<const char*>(extension_count);
    sdl_assert(SDL_Vulkan_GetInstanceExtensions(window, &extension_count,
                                                extensions.data()));
}

void Engine::vk_create_instance()
{
    vk::ApplicationInfo app_info{
        .pApplicationName = config.application_name.c_str(),
        .applicationVersion = VK_MAKE_API_VERSION(
            0, config.application_version.major,
            config.application_version.minor, config.application_version.patch),
        .pEngineName = "ipkengine",
        .engineVersion =
            VK_MAKE_API_VERSION(0, config::VERSION_MAJOR, config::VERSION_MINOR,
                                config::VERSION_PATCH),
        .apiVersion = VK_API_VERSION_1_0};

    vk::InstanceCreateInfo create_info{
        .pApplicationInfo = &app_info,
        .enabledLayerCount = static_cast<uint32_t>(layers.size()),
        .ppEnabledLayerNames = layers.data(),
        .enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
        .ppEnabledExtensionNames = extensions.data()};

    vk_instance = vk::createInstance(create_info);
}
