// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file renderer.cc
/// @brief Vulkan renderer member definitions.

#include <isopunk/engine/renderer.h>

#include <memory>

#include <isopunk/engine/config.h>
#include <isopunk/engine/window.h>

using namespace isopunk;

Renderer::Renderer(EngineConfig const& conf, WindowPtr& wnd)
{
    ext  = get_extensions(wnd, ctx);
    inst = create_instance(conf, ctx, ext);
#ifndef NDEBUG
    dbg_messenger = create_debug_messenger(inst);
#endif
    phys_dev = std::make_unique<vkr::PhysicalDevice>(
        *inst, *get_physical_devices(inst).front());
    surface    = create_surface(wnd, inst);
    queue_idx  = get_queue_indices(phys_dev, surface);
    dev        = create_device(phys_dev, queue_idx);
    queues     = get_queues(queue_idx, dev);
    cmd_pool   = create_command_pool(dev, queue_idx);
    cmd_buffer = allocate_command_buffer(dev, cmd_pool);
}
