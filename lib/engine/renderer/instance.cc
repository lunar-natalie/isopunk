// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file instance.cc
/// @brief Vulkan instance management.

#include <isopunk/engine/renderer.h>

#include <memory>

#include <vulkan/vulkan_raii.hpp>
#include <vulkan/vulkan_structs.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/defs.h>
#include <isopunk/version.h>

using namespace isopunk;

vkptr::Instance Renderer::create_instance(vkr::Context& context,
                                          const EngineConfig& config)
{
    vk::ApplicationInfo app_info{
        .pApplicationName = config.application_name.c_str(),
        .applicationVersion = config.application_version.vk_make_api_version(),
        .pEngineName = ENGINE_NAME,
        .engineVersion = ENGINE_VERSION.vk_make_api_version(),
        .apiVersion = VK_API_VERSION_1_0};

    try {
        return std::make_shared<vkr::Instance>(
            context, vk::InstanceCreateInfo{{}, &app_info});
    }
    catch (vk::SystemError& e) {
        throw std::runtime_error(e.what());
    }
}
