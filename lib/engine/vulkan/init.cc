// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file init.cc
/// @brief Vulkan initialization and deinitialization.

#include <isopunk/engine.h>

using namespace isopunk;

void Engine::vk_init()
{
    // TODO
    vk_get_instance_extensions();
    vk_create_instance();
    vk_create_surface();
    vk_get_physical_devices();
    vk_create_device();
}

void Engine::vk_deinit() noexcept
{
    vk_device.freeCommandBuffers(vk_command_pool, vk_command_buffer);
    vk_device.destroyCommandPool(vk_command_pool);
    vk_device.destroy();
    vk_instance.destroy();
}
