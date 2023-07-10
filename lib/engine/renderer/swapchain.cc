// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file swapchain.cc
/// @brief Vulkan swapchain management.

#include <isopunk/engine/renderer.h>
#include <isopunk/engine/renderer/swapchain.h>

#include <algorithm>
#include <memory>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/renderer/surface.h>

using namespace isopunk;

vkx::Swapchain::Swapchain(vkptr::Device const&       dev,
                          vk::SwapchainCreateInfoKHR info)
    : vkr::SwapchainKHR(*dev, info)
{
    // Load image views from images requested by the surface
    auto images = getImages();
    m_image_views.reserve(images.size());
    vk::ImageViewCreateInfo img_view_info{
        .viewType         = vk::ImageViewType::e2D,
        .format           = info.imageFormat,
        .subresourceRange = {vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1}};
    for (auto img : images) {
        img_view_info.image = img;
        m_image_views.emplace_back(*dev, img_view_info);
    }
}

vkptr::Swapchain
Renderer::create_swapchain(vkptr::PhysicalDevice const& phys_dev,
                           vkptr::Device const&         dev,
                           vkptr::Surface const&        surface,
                           vkx::QueueIndexPair const&   queue_idx)
{
    vk::Extent2D extent;
    if (surface->capabilities.currentExtent.width
        == std::numeric_limits<uint32_t>::max()) {
        // If the surface extent is undefined, use the size of the requested
        // images
        extent.width  = std::clamp(extent.width,
                                  surface->capabilities.minImageExtent.width,
                                  surface->capabilities.maxImageExtent.width);
        extent.height = std::clamp(extent.height,
                                   surface->capabilities.minImageExtent.height,
                                   surface->capabilities.maxImageExtent.height);
    }
    else {
        extent = surface->capabilities.currentExtent;
    }

    vk::SwapchainCreateInfoKHR info = {
        .surface          = **surface,
        .minImageCount    = surface->capabilities.minImageCount,
        .imageFormat      = surface->format().format,
        .imageColorSpace  = surface->format().colorSpace,
        .imageExtent      = extent,
        .imageArrayLayers = 1,
        .imageUsage       = vk::ImageUsageFlagBits::eColorAttachment
                      | vk::ImageUsageFlagBits::eTransferSrc,
        .imageSharingMode = vk::SharingMode::eExclusive,
        .preTransform     = surface->pre_transform(),
        .compositeAlpha   = surface->composite_alpha(),
        .presentMode      = surface->present_mode(),
        .clipped          = true};

    if (!queue_idx.equal()) {
        // If the graphics and present queues are from different queue families,
        // we either have to explicitly transfer
        // ownership of images between the queues, or we have to create the
        // swapchain with imageSharingMode as VK_SHARING_MODE_CONCURRENT
        auto v_idx                 = queue_idx.to_vector();
        info.imageSharingMode      = vk::SharingMode::eConcurrent;
        info.queueFamilyIndexCount = v_idx.size();
        info.pQueueFamilyIndices   = v_idx.data();
    }

    return std::make_unique<vkx::Swapchain>(dev, info);
}
