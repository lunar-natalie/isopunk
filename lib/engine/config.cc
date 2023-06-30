// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file config.cc
/// @brief Engine configuration definitions.

#include <isopunk/engine.h>

#include <isopunk/engine/config.h>

#include <isopunk/version.h>

using namespace isopunk;

const EngineConfig Engine::default_conf{.app_name      = "IsoPunk",
                                        .app_version   = ENGINE_VERSION,
                                        .window_width  = 800,
                                        .window_height = 600};
