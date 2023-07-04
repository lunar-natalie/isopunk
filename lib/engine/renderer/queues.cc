// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file queues.cc
/// @brief Vulkan queue management.

#include <isopunk/engine/renderer.h>

#include <cstdint>
#include <iterator>
#include <limits>
#include <stdexcept>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/renderer/queues.h>
#include <isopunk/engine/utils.h>

using namespace isopunk;

vkx::QueueIndexPair
Renderer::get_queue_indices(vkptr::PhysicalDevice const& phys_dev,
                            vkptr::SurfaceKHR const&     surface)
{
    vkx::QueueIndexPair                                    queue_idx;
    std::vector<vk::QueueFamilyProperties>::const_iterator prop_itr;

    auto props = phys_dev->getQueueFamilyProperties();
    runtime_assert(props.size() < std::numeric_limits<std::uint32_t>::max(),
                   "Queue family properties out of range");

    // Find first index into properties which supports graphics
    prop_itr = std::find_if(
        props.begin(), props.end(), [](vk::QueueFamilyProperties const& qfp) {
            return qfp.queueFlags & vk::QueueFlagBits::eGraphics;
        });

    if (prop_itr != props.end()) {
        // Set graphics index if found
        queue_idx.gfx =
            static_cast<std::uint32_t>(std::distance(props.cbegin(), prop_itr));

        // Check if first index supports present
        if (phys_dev->getSurfaceSupportKHR(queue_idx.gfx, **surface)) {
            queue_idx.present = queue_idx.gfx;
            // Return using single queue index
            return queue_idx;
        }

        // Find next index supporting present
        for (size_t i = 0; i < props.size(); ++i) {
            if (phys_dev->getSurfaceSupportKHR(static_cast<std::uint32_t>(i),
                                               **surface)) {
                queue_idx.present = i;
                // Return using separate graphics and queue index
                return queue_idx;
            }
        }
    }

    throw std::runtime_error("Failed to accquire queue family indices");
}

vkptr::QueuePair Renderer::create_queues(vkx::QueueIndexPair const& idx,
                                         vkptr::Device const&       dev)
{
    return std::make_shared<vkx::QueuePair>(idx, dev);
}
