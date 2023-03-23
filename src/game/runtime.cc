// IsoPunk
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file runtime.cc
/// @brief Implementation of game runtime methods.

#include "game.h"

using namespace isopunk;

void Game::start()
{
    init();
    run();
}
