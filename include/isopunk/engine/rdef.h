// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file rdef.h
/// @brief Renderer type definitions.

#ifndef ISOPUNK_ENGINE_RDEF_H
#define ISOPUNK_ENGINE_RDEF_H

#include <memory>
#include <vector>

#include <vulkan/vulkan_raii.hpp>

namespace isopunk {

/// @brief Vulkan RAII namespace alias.
namespace vkr {

using namespace vk::raii;

} // namespace vkr

/// @brief Movable pointer types for Vulkan objects.
namespace vkptr {

typedef std::unique_ptr<vkr::Instance>               Instance;
typedef std::unique_ptr<vkr::PhysicalDevice>         PhysicalDevice;
typedef std::unique_ptr<vkr::DebugUtilsMessengerEXT> DebugUtilsMessengerEXT;
typedef std::unique_ptr<vkr::Queue>                  Queue;
typedef std::unique_ptr<vkr::Device>                 Device;
typedef std::unique_ptr<vkr::CommandPool>            CommandPool;
typedef std::unique_ptr<vkr::CommandBuffer>          CommandBuffer;
typedef std::unique_ptr<vkr::SwapchainKHR>           SwapchainKHR;

} // namespace vkptr

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RDEF_H
