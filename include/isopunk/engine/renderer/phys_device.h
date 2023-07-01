// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file phys_device.h
/// @brief Inline Vulkan physical device utilities.

#ifndef ISOPUNK_ENGINE_RENDERER_PHYS_DEVICE_H
#define ISOPUNK_ENGINE_RENDERER_PHYS_DEVICE_H

#include <memory>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/renderer.h>

namespace isopunk {
namespace utils {

inline vkptr::PhysicalDevice
create_physical_device(vkptr::Instance const& inst,
                       vkr::PhysicalDevice&   phys_dev)
{
    return std::make_unique<vkr::PhysicalDevice>(*inst, *phys_dev);
}

} // namespace utils
} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_PHYS_DEVICE_H
