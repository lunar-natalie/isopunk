// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file swapchain.h
/// @brief Vulkan swapchain utility header.

#ifndef ISOPUNK_ENGINE_RENDERER_SWAPCHAIN_H
#define ISOPUNK_ENGINE_RENDERER_SWAPCHAIN_H

#include <memory>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>

namespace isopunk {

namespace vkx {

/// @brief Vulkan swapchain wrapper.
class Swapchain : public vkr::SwapchainKHR {
public:
    Swapchain(vkptr::Device const& dev, vk::SwapchainCreateInfoKHR info);

private:
};

} // namespace vkx

namespace vkptr {

typedef std::shared_ptr<vkx::Swapchain> Swapchain;

} // namespace vkptr

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_SWAPCHAIN_H
