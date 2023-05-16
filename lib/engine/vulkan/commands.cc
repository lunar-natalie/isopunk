// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file commands.cc
/// @brief Vulkan command pool and buffer.

#include <isopunk/engine.h>

#include <vulkan/vulkan.hpp>

using namespace isopunk;

void Engine::vk_create_command_buffer()
{
    vk::CommandPoolCreateInfo pool_create_info = {
        .flags = vk::CommandPoolCreateFlags(),
        .queueFamilyIndex = vk_queue_family_indices.graphics};

    vk_command_pool = vk_device.createCommandPool(pool_create_info);

    vk::CommandBufferAllocateInfo buffer_alloc_info = {
        .commandPool = vk_command_pool,
        .level = vk::CommandBufferLevel::ePrimary,
        .commandBufferCount = 1};

    vk_command_buffer =
        vk_device.allocateCommandBuffers(buffer_alloc_info).front();
}
