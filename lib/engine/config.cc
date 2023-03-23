// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file config.cc
/// @brief Engine configuration definitions.

#include <isopunk/engine/config.h>

#include <isopunk/version.h>

using namespace isopunk;

const EngineConfig EngineConfig::default_config{.application_name = "IsoPunk",
                                                .application_version =
                                                    config::ENGINE_VERSION,
                                                .window_width = 800,
                                                .window_height = 600};
