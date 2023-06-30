// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file queues.h
/// @brief Vulkan queue definitions.

#ifndef ISOPUNK_ENGINE_RENDERER_QUEUES_H
#define ISOPUNK_ENGINE_RENDERER_QUEUES_H

#include <cstdint>
#include <memory>

#include <vulkan/vulkan_raii.hpp>

#include <isopunk/engine/rdef.h>

namespace isopunk {

namespace vkx {

struct QueueIndexPair;
struct QueuePair;

} // namespace vkx

namespace vkptr {

typedef std::shared_ptr<vkx::QueueIndexPair> QueueIndexPair;
typedef std::shared_ptr<vkx::QueuePair>      QueuePair;

} // namespace vkptr

namespace vkx {

/// @brief Holds the index of each available queue family for a given physical
/// device.
struct QueueIndexPair {
    uint32_t gfx;     /// @brief Graphics queue index
    uint32_t present; /// @brief Present queue index
};

/// @brief Holds a queue object for each queue family for a given physical
/// device.
struct QueuePair {
    vkr::Queue gfx;     /// @brief Graphics queue
    vkr::Queue present; /// @brief Present queue

    QueuePair(vkptr::QueueIndexPair const& idx, vkptr::Device const& dev)
        : gfx{*dev, idx->gfx, 0},
          present{*dev, idx->present, 0}
    {
    }
};

} // namespace vkx

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_QUEUES_H
