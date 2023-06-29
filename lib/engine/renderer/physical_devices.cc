// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file physical_devices.cc
/// @brief Vulkan physical devices.

#include <isopunk/engine/renderer.h>

#include <memory>
#include <utility>

#include <vulkan/vulkan_raii.hpp>
#include <vulkan/vulkan_structs.hpp>

#include <isopunk/engine/defs.h>
#include <isopunk/engine/utils.h>

using namespace isopunk;

std::pair<vkptr::PhysicalDevice, vkptr::PhysicalDevices>
Renderer::get_physical_devices(vkptr::Instance& instance)
{
    vkr::PhysicalDevices physical_devices(*instance.get());
    runtime_assert(physical_devices.size() > 0, "No physical devices found");
    return std::make_pair(
        std::make_unique<vkr::PhysicalDevice>(physical_devices.front()),
        std::make_shared<std::vector<vkr::PhysicalDevice>>(physical_devices));
}
