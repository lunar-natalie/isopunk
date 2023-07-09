// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file queues.h
/// @brief Vulkan queue utility header.

#ifndef ISOPUNK_ENGINE_RENDERER_QUEUES_H
#define ISOPUNK_ENGINE_RENDERER_QUEUES_H

#include <cstdint>
#include <memory>
#include <vector>

#include <isopunk/engine/rdef.h>

namespace isopunk {

namespace vkx {

/// @brief Holds the index of each available queue family for a given physical
/// device.
struct QueueIndexPair {
    std::uint32_t gfx;     /// @brief Graphics queue index
    std::uint32_t present; /// @brief Present queue index

    bool equal() const
    {
        return gfx == present;
    }

    std::vector<std::uint32_t> to_vector() const
    {
        return std::vector(gfx, present);
    }
};

/// @brief Holds a queue object for each queue family for a given physical
/// device.
struct QueuePair {
    vkr::Queue gfx;     /// @brief Graphics queue
    vkr::Queue present; /// @brief Present queue

    QueuePair(QueueIndexPair const& idx, vkptr::Device const& dev)
        : gfx{*dev, idx.gfx, 0},
          present{*dev, idx.present, 0}
    {
    }
};

} // namespace vkx

namespace vkptr {

typedef std::shared_ptr<vkx::QueuePair> QueuePair;

} // namespace vkptr

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_QUEUES_H
