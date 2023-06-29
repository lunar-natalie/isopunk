// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file config.h
/// @brief Engine configuration.

#ifndef ISOPUNK_ENGINE_DEFS_H
#define ISOPUNK_ENGINE_DEFS_H

#include <memory>
#include <vulkan/vulkan_raii.hpp>

/// @brief Vulkan RAII namespace alias.
namespace vkr {

using namespace vk::raii;

} // namespace vkr

/// @brief Movable pointer types for Vulkan objects.
namespace vkptr {

typedef std::shared_ptr<vkr::Instance> Instance;
typedef std::unique_ptr<vkr::PhysicalDevice> PhysicalDevice;
typedef std::shared_ptr<std::vector<vkr::PhysicalDevice>> PhysicalDevices;
typedef std::unique_ptr<vkr::SurfaceKHR> SurfaceKHR;

} // namespace vkptr

#endif // ISOPUNK_ENGINE_DEFS_H
