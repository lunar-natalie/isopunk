// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file renderer.cc
/// @brief Vulkan renderer member definitions.

#include <isopunk/engine/renderer.h>

#include <isopunk/engine/config.h>
#include <isopunk/engine/window.h>

using namespace isopunk;

Renderer::Renderer(EngineConfig const& conf, WindowPtr& wnd)
{
    ext       = get_extensions(wnd);
    inst      = create_instance(conf, ctx, ext);
    phys_dev  = get_physical_devices(inst).first;
    surface   = create_surface(wnd, inst);
    queue_idx = get_queue_indices(phys_dev, surface);
    dev       = create_device(phys_dev, queue_idx);
    queues    = get_queues(queue_idx, dev);
}
