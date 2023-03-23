// IsoPunk
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file game.cc
/// @brief Game constructor and destructor implementation.

#include "game.h"

#include <isopunk/engine.h>

using namespace isopunk;

Game::Game()
    : Engine()
{
}

Game::~Game()
{
    terminate();
}
