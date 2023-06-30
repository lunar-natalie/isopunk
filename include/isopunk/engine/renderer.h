// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file renderer.h
/// @brief Vulkan graphics renderer.

#ifndef ISOPUNK_ENGINE_RENDERER_H
#define ISOPUNK_ENGINE_RENDERER_H

#include <utility>
#include <vector>

#include <vulkan/vulkan_raii.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/rdef.h>
#include <isopunk/engine/renderer/queues.h>
#include <isopunk/engine/window.h>

namespace isopunk {

/// @brief Graphics renderer class.
///
/// Manages the Vulkan runtime and provides utilities for displaying graphical
/// objects.
class Renderer {
public:
    /// @brief Initializes a renderer instance.
    ///
    /// @note SDL must be initialized before initializing the renderer.
    ///
    /// @param conf Engine configuration.
    /// @param wnd Reference to a unique pointer to an initialized SDL window.
    ///
    /// @throw std::runtime_error A critical renderer operation or Vulkan API
    /// call has failed. The application should be terminated.
    Renderer(EngineConfig const& conf, WindowPtr& wnd);

private:
    vkr::Context          ctx;
    vkptr::Instance       inst;
    vkptr::PhysicalDevice phys_dev;
    vkptr::SurfaceKHR     surface;
    vkptr::QueueIndexPair queue_idx;
    vkptr::QueuePair      queues;
    vkptr::Device         dev;

    static std::vector<const char*> get_extensions(WindowPtr& wnd);

    static vkptr::Instance create_instance(EngineConfig const& config,
                                           vkr::Context&       ctx,
                                           WindowPtr&          wnd);

    static std::pair<vkptr::PhysicalDevice, vkptr::PhysicalDevices>
    get_physical_devices(vkptr::Instance const& inst);

    static vkptr::SurfaceKHR create_surface(WindowPtr&       wnd,
                                            vkptr::Instance& inst);

    static vkptr::QueueIndexPair
    get_queue_indices(vkptr::PhysicalDevice const& phys_dev,
                      vkptr::SurfaceKHR const&     surface);

    static vkptr::QueuePair get_queues(vkptr::QueueIndexPair const& idx,
                                       vkptr::Device&               dev);
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_H
