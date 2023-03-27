// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file device.cc
/// @brief Vulkan rendering device setup.

#include <isopunk/engine.h>

#include <cstdint>
#include <set>
#include <vector>

#include <vulkan/vulkan.hpp>

using namespace isopunk;

void Engine::vk_create_device()
{
    const std::vector<const char*> device_extensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    const float queue_priorities[] = {1.0f};

    std::vector<vk::DeviceQueueCreateInfo> queue_create_infos;
    std::set<uint32_t> unique_queue_families = {
        vk_queue_family_indices.graphics, vk_queue_family_indices.present};

    auto queue_priority = queue_priorities[0];
    for (auto queue_family : unique_queue_families) {
        vk::DeviceQueueCreateInfo queue_create_info = {
            .queueFamilyIndex = queue_family,
            .queueCount = 1,
            .pQueuePriorities = &queue_priority};
        queue_create_infos.push_back(queue_create_info);
    }

    vk::DeviceQueueCreateInfo queue_create_info = {
        .queueFamilyIndex = vk_queue_family_indices.graphics,
        .queueCount = 1,
        .pQueuePriorities = &queue_priority};

    vk::PhysicalDeviceFeatures device_features = {
        // https://en.wikipedia.org/wiki/Anisotropic_filtering
        .samplerAnisotropy = VK_TRUE};

    vk::DeviceCreateInfo create_info = {
        .queueCreateInfoCount =
            static_cast<uint32_t>(queue_create_infos.size()),
        .pQueueCreateInfos = queue_create_infos.data(),
        .enabledLayerCount = static_cast<uint32_t>(vk_layers.size()),
        .ppEnabledLayerNames = vk_layers.data(),
        .enabledExtensionCount =
            static_cast<uint32_t>(device_extensions.size()),
        .ppEnabledExtensionNames = device_extensions.data(),
        .pEnabledFeatures = &device_features};

    vk_device = vk_physical_device.createDevice(create_info);

    vk_queues = {
        .graphics = vk_device.getQueue(vk_queue_family_indices.graphics, 0),
        .present = vk_device.getQueue(vk_queue_family_indices.present, 0)};
}
