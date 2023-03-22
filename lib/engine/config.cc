// This file is part of the ipkengine library.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <isopunk/engine/config.h>

#include <isopunk/version.h>

using namespace isopunk;

const EngineConfig EngineConfig::default_config{
    .application_name = "IsoPunk",
    .application_version = {.major = config::VERSION_MAJOR,
                            .minor = config::VERSION_MINOR,
                            .patch = config::VERSION_PATCH},
    .window_width = 800,
    .window_height = 600};
