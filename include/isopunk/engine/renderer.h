// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file renderer.h
/// @brief Vulkan graphics renderer.

#ifndef ISOPUNK_ENGINE_RENDERER_H
#define ISOPUNK_ENGINE_RENDERER_H

#include <utility>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/rdef.h>
#include <isopunk/engine/renderer/phys_device.h>
#include <isopunk/engine/renderer/queues.h>
#include <isopunk/engine/renderer/surface.h>
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
    vkr::Context    ctx;
    vkptr::Instance inst;
#ifndef NDEBUG
    vkptr::DebugUtilsMessengerEXT dbg_messenger;
#endif
    vkptr::PhysicalDevices phys_devs;
    vkptr::PhysicalDevice  phys_dev;
    vkptr::Surface         surface;
    vkx::QueueIndexPair    queue_idx;
    vkptr::QueuePair       queues;
    vkptr::Device          dev;
    vkptr::CommandPool     cmd_pool;
    vkptr::CommandBuffer   cmd_buffer;
    vkptr::SwapchainKHR    swapchain;

    static vkptr::Instance create_instance(EngineConfig const& config,
                                           WindowPtr&          wnd,
                                           vkr::Context&       ctx);

    static std::vector<const char*>
    get_instance_extensions(WindowPtr& wnd, vkr::Context const& ctx);

#ifndef NDEBUG
    static vkptr::DebugUtilsMessengerEXT
    create_debug_messenger(vkptr::Instance& inst);
#endif

    static vkptr::PhysicalDevices
    get_physical_devices(vkptr::Instance const& inst);

    static vkptr::Surface create_surface(WindowPtr&                   wnd,
                                         vkptr::Instance&             inst,
                                         vkptr::PhysicalDevice const& phys_dev);

    static vkx::QueueIndexPair
    get_queue_indices(vkptr::PhysicalDevice const& phys_dev,
                      vkptr::Surface const&        surface);

    static vkptr::Device create_device(vkptr::PhysicalDevice const& phys_dev,
                                       vkx::QueueIndexPair const&   queue_idx);

    static vkx::QueuePair get_queues(vkx::QueueIndexPair const& idx,
                                     vkptr::Device&             dev);

    static vkptr::QueuePair create_queues(vkx::QueueIndexPair const& idx,
                                          vkptr::Device const&       dev);

    static vkptr::CommandPool
    create_command_pool(vkptr::Device&             dev,
                        vkx::QueueIndexPair const& queue_idx);

    static vkptr::CommandBuffer
    allocate_command_buffer(vkptr::Device& dev, vkptr::CommandPool& pool);

    static vkptr::SwapchainKHR
    create_swapchain(vkptr::PhysicalDevice const& phys_dev,
                     vkptr::Device const&         dev,
                     vkptr::Surface const&        surface,
                     vkx::QueueIndexPair const&   queue_idx);

#ifndef NDEBUG
    static VKAPI_ATTR VkBool32 VKAPI_CALL debug_messenger_callback(
        VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
        VkDebugUtilsMessengerCallbackDataEXT const* pCallbackData,
        void* /*pUserData*/);
#endif
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_RENDERER_H
