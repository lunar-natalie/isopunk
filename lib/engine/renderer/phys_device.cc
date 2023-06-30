// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file phys_device.cc
/// @brief Vulkan physical devices.

#include <isopunk/engine/renderer.h>

#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>
#include <vector>

#include <vulkan/vulkan_structs.hpp>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/renderer/queues.h>
#include <isopunk/engine/utils.h>

using namespace isopunk;

std::pair<vkptr::PhysicalDevice, vkptr::PhysicalDevices>
Renderer::get_physical_devices(vkptr::Instance const& inst)
{
    auto phys_devs = inst->enumeratePhysicalDevices();
    runtime_assert(phys_devs.size() > 0, "No physical devices found");
    return std::make_pair(
        std::make_unique<vkr::PhysicalDevice>(phys_devs.front()),
        std::make_shared<std::vector<vkr::PhysicalDevice>>(phys_devs));
}
