// Game runtime methods.
//
// This file is part of IsoPunk.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "game.h"

using namespace isopunk;

void Game::start()
{
    init();
    run();
}
