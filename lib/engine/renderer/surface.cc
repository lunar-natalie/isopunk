// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file surface.cc
/// @brief Vulkan surface implementation and management routines.

#include <isopunk/engine/renderer.h>
#include <isopunk/engine/renderer/surface.h>

#include <algorithm>
#include <memory>

#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/utils.h>
#include <isopunk/engine/window.h>

using namespace isopunk;

vkx::Surface::Surface(vkptr::PhysicalDevice const& phys_dev,
                      vkptr::Instance const&       inst,
                      VkSurfaceKHR&                data)
    : vkr::SurfaceKHR(*inst, data),
      phys_dev{phys_dev},
      capabilities{phys_dev->getSurfaceCapabilitiesKHR(**this)}
{
    m_format          = get_format();
    m_pre_transform   = get_pre_transform();
    m_composite_alpha = get_composite_alpha();
    m_present_mode    = get_present_mode();
}

vk::SurfaceFormatKHR vkx::Surface::get_format()
{
    auto formats = phys_dev->getSurfaceFormatsKHR(**this);
    runtime_assert(!formats.empty(),
                   "No surface formats available for current physical device");

    auto res             = formats.front();
    auto req_color_space = vk::ColorSpaceKHR::eSrgbNonlinear;
    if (formats.size() == 1) {
        if (res.format == vk::Format::eUndefined) {
            res.format     = vk::Format::eB8G8R8A8Unorm;
            res.colorSpace = req_color_space;
        }
    }
    else {
        vk::Format req_formats[] = {vk::Format::eB8G8R8A8Unorm,
                                    vk::Format::eR8G8B8A8Unorm,
                                    vk::Format::eB8G8R8Unorm,
                                    vk::Format::eR8G8B8Unorm};
        for (auto& req_format : req_formats) {
            auto it = std::find_if(
                formats.begin(),
                formats.end(),
                [req_format, req_color_space](vk::SurfaceFormatKHR const& f) {
                    return (f.format == req_format)
                           && (f.colorSpace == req_color_space);
                });
            if (it != formats.end()) {
                res = *it;
                break;
            }
        }
    }

    runtime_assert(res.colorSpace == req_color_space,
                   "Unable to find a compatible surface format");
    return res;
}

vk::SurfaceTransformFlagBitsKHR vkx::Surface::get_pre_transform()
{
    return (capabilities.supportedTransforms
            & vk::SurfaceTransformFlagBitsKHR::eIdentity)
               ? vk::SurfaceTransformFlagBitsKHR::eIdentity
               : capabilities.currentTransform;
}

vk::CompositeAlphaFlagBitsKHR vkx::Surface::get_composite_alpha()
{
    return (capabilities.supportedCompositeAlpha
            & vk::CompositeAlphaFlagBitsKHR::ePreMultiplied)
               ? vk::CompositeAlphaFlagBitsKHR::ePreMultiplied
           : (capabilities.supportedCompositeAlpha
              & vk::CompositeAlphaFlagBitsKHR::ePostMultiplied)
               ? vk::CompositeAlphaFlagBitsKHR::ePostMultiplied
           : (capabilities.supportedCompositeAlpha
              & vk::CompositeAlphaFlagBitsKHR::eInherit)
               ? vk::CompositeAlphaFlagBitsKHR::eInherit
               : vk::CompositeAlphaFlagBitsKHR::eOpaque;
}

vk::PresentModeKHR vkx::Surface::get_present_mode()
{
    auto modes = phys_dev->getSurfacePresentModesKHR(**this);
    auto res   = vk::PresentModeKHR::eFifo;
    for (const auto& m : modes) {
        if (m == vk::PresentModeKHR::eMailbox) {
            res = m;
            break;
        }

        if (m == vk::PresentModeKHR::eImmediate) {
            res = m;
        }
    }
    return res;
}

vkptr::Surface Renderer::create_surface(WindowPtr&                   wnd,
                                        vkptr::Instance&             inst,
                                        vkptr::PhysicalDevice const& phys_dev)
{
    VkSurfaceKHR s_data;
    sdl_assert(SDL_Vulkan_CreateSurface(
        wnd->data, static_cast<VkInstance>(**inst), &s_data));
    return std::make_unique<vkx::Surface>(phys_dev, inst, s_data);
}
