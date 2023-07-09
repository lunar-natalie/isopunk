// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file phys_device.h
/// @brief Vulkan physical device utility header.

#ifndef ISOPUNK_ENGINE_RENDERER_PHYS_DEVICE_H
#define ISOPUNK_ENGINE_RENDERER_PHYS_DEVICE_H

#include <memory>
#include <vector>

#include <isopunk/engine/rdef.h>

namespace isopunk {

namespace vkx {

/// @brief Vulkan physical device vector wrapper.
class PhysicalDevices : public std::vector<vkr::PhysicalDevice> {
public:
    PhysicalDevices(vkptr::Instance const& inst)
        : std::vector<vkr::PhysicalDevice>(inst->enumeratePhysicalDevices()),
          inst{inst}
    {
    }

    /// @return std::unique_ptr to the first physical device.
    vkptr::PhysicalDevice pfront()
    {
        return std::make_unique<vkr::PhysicalDevice>(*inst, *front());
    }

private:
    vkptr::Instance const& inst;
};

} // namespace vkx

namespace vkptr {

typedef std::shared_ptr<vkx::PhysicalDevices> PhysicalDevices;

} // namespace vkptr

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_PHYS_DEVICE_H
