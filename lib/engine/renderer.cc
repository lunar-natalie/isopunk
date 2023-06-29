// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file renderer.cc
/// @brief Vulkan renderer member definitions.

#include "isopunk/engine/config.h"
#include <isopunk/engine/renderer.h>

using namespace isopunk;

Renderer::Renderer(const EngineConfig& config)
{
    instance = create_instance(config);
}
