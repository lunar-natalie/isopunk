// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file device.cc
/// @brief Vulkan device management.

#include <isopunk/engine.h>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/utils.h>

using namespace isopunk;

void Engine::vk_get_physical_devices()
{
    vk_physical_devices = vk_instance.enumeratePhysicalDevices();
    runtime_assert(vk_physical_devices.size() > 0, "No physical devices");
    vk_physical_device = vk_physical_devices.front();
}
