// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file swapchain.cc
/// @brief Vulkan swapchain management.

#include <isopunk/engine/renderer.h>
#include <isopunk/engine/renderer/swapchain.h>

#include <memory>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>
#include <isopunk/engine/renderer/surface.h>

using namespace isopunk;

vkx::Swapchain::Swapchain(vkptr::Device const&       dev,
                          vk::SwapchainCreateInfoKHR info)
    : vkr::SwapchainKHR(*dev, info)
{
    auto images = getImages();
    image_views.reserve(images.size());
    vk::ImageViewCreateInfo img_view_info{
        .viewType         = vk::ImageViewType::e2D,
        .format           = info.imageFormat,
        .subresourceRange = {vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1}};
    for (auto image : images) {
        img_view_info.image = image;
        image_views.emplace_back(*dev, img_view_info);
    }
}

vkptr::Swapchain
Renderer::create_swapchain(vkptr::PhysicalDevice const& phys_dev,
                           vkptr::Device const&         dev,
                           vkptr::Surface const&        surface,
                           vkx::QueueIndexPair const&   queue_idx)
{
    vk::SwapchainCreateInfoKHR info = {
        .surface          = **surface,
        .minImageCount    = surface->capabilities.minImageCount,
        .imageFormat      = surface->format().format,
        .imageColorSpace  = surface->format().colorSpace,
        .imageExtent      = surface->extent,
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
