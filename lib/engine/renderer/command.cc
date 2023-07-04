// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file command.cc
/// @brief Vulkan command pool and buffer management.

#include <isopunk/engine/renderer.h>

#include <memory>
#include <utility>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>

using namespace isopunk;

vkptr::CommandPool
Renderer::create_command_pool(vkptr::Device&             dev,
                              vkx::QueueIndexPair const& queue_idx)
{
    return std::make_unique<vkr::CommandPool>(
        dev->createCommandPool({.queueFamilyIndex = queue_idx.gfx}));
}

vkptr::CommandBuffer Renderer::allocate_command_buffer(vkptr::Device&      dev,
                                                       vkptr::CommandPool& pool)
{
    return std::make_unique<vkr::CommandBuffer>(std::move(
        dev->allocateCommandBuffers({.commandPool = **pool,
                                     .level = vk::CommandBufferLevel::ePrimary,
                                     .commandBufferCount = 1})
            .front()));
}
