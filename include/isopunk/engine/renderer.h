// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file renderer.h
/// @brief Vulkan renderer class.

#ifndef ISOPUNK_ENGINE_RENDERER_H
#define ISOPUNK_ENGINE_RENDERER_H

#include <utility>

#include <vulkan/vulkan_raii.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/defs.h>

namespace isopunk {

class Renderer {
public:
    Renderer(const EngineConfig& config);

private:
    static vkptr::Instance create_instance(vkr::Context& context,
                                           const EngineConfig& config);

    static std::pair<vkptr::PhysicalDevice, vkptr::PhysicalDevices>
    get_physical_devices(vkptr::Instance& instance);

    vkr::Context context;
    vkptr::Instance instance;
    vkptr::PhysicalDevice physical_device;
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_H
