// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file phys_device.cc
/// @brief Vulkan physical devices.

#include <isopunk/engine/renderer.h>

#include <memory>
#include <stdexcept>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/utils.h>

using namespace isopunk;

vkx::PhysicalDevices Renderer::get_physical_devices(vkptr::Instance const& inst)
{
    auto phys_devs = inst->enumeratePhysicalDevices();
    runtime_assert(phys_devs.size() > 0, "No physical devices found");
    return phys_devs;
}
