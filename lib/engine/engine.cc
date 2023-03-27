// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file engine.cc
/// @brief Engine constructor implementation.

#include <isopunk/engine.h>

#include <isopunk/engine/config.h>

using namespace isopunk;

Engine::Engine(EngineConfig config)
    : config{config}
{
}
