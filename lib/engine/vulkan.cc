// Vulkan management.
//
// This file is part of the ipkengine library.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <isopunk/engine.h>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/utils.h>
#include <isopunk/version.h>

using namespace isopunk;

void Engine::init_vk()
{
    // TODO
    create_vk_instance();
}

void Engine::create_vk_instance()
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

    sdl_assert(SDL_Vulkan_GetInstanceExtensions(window, &extension_count,
                                                extension_names));

    // TODO
    // vk::InstanceCreateInfo create_info{.pApplicationInfo = &app_info};
}
