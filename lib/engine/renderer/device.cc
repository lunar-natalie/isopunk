// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file device.cc
/// @brief Vulkan device management.

#include <isopunk/engine/renderer.h>

#include <memory>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>

using namespace isopunk;

vkptr::Device Renderer::create_device(vkptr::PhysicalDevice const& phys_dev,
                                      vkx::QueueIndexPair const&   queue_idx)
{

    float                     queue_priorities[] = {0.0f};
    vk::DeviceQueueCreateInfo gfx_info = {.queueFamilyIndex = queue_idx.gfx,
                                          .queueCount       = 1,
                                          .pQueuePriorities = queue_priorities};
    return std::make_unique<vkr::Device>(
        *phys_dev,
        vk::DeviceCreateInfo{.queueCreateInfoCount = 1,
                             .pQueueCreateInfos    = &gfx_info});
}
