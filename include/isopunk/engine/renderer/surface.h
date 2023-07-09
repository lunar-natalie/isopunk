// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file surface.h
/// @brief Vulkan surface utility header.

#ifndef ISOPUNK_ENGINE_RENDERER_SURFACE_H
#define ISOPUNK_ENGINE_RENDERER_SURFACE_H

#include <memory>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>

namespace isopunk {

namespace vkx {

/// @brief Vulkan surface wrapper.
class Surface : public vkr::SurfaceKHR {
public:
    Surface(vkptr::PhysicalDevice const& phys_dev,
            vkptr::Instance const&       inst,
            VkSurfaceKHR&                data,
            vk::Extent2D&                extent);

    const vk::SurfaceCapabilitiesKHR capabilities;
    const vk::Extent2D               extent;

protected:
    const vkptr::PhysicalDevice&    phys_dev;
    vk::SurfaceFormatKHR            m_format;
    vk::SurfaceTransformFlagBitsKHR m_pre_transform;
    vk::CompositeAlphaFlagBitsKHR   m_composite_alpha;
    vk::PresentModeKHR              m_present_mode;

public:
    vk::SurfaceFormatKHR format()
    {
        return m_format;
    }
    vk::SurfaceTransformFlagBitsKHR pre_transform()
    {
        return m_pre_transform;
    }
    vk::CompositeAlphaFlagBitsKHR composite_alpha()
    {
        return m_composite_alpha;
    }
    vk::PresentModeKHR present_mode()
    {
        return m_present_mode;
    }

private:
    vk::SurfaceFormatKHR            get_format();
    vk::SurfaceTransformFlagBitsKHR get_pre_transform();
    vk::CompositeAlphaFlagBitsKHR   get_composite_alpha();
    vk::PresentModeKHR              get_present_mode();
};

} // namespace vkx

namespace vkptr {

typedef std::unique_ptr<vkx::Surface> Surface;

} // namespace vkptr

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_SURFACE_H
