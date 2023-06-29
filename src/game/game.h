// IsoPunk
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file game.h
/// @brief Game class header.

#ifndef GAME_H
#define GAME_H

#include <isopunk/engine.h>

namespace isopunk {

class Game : public Engine {
public:
    Game();
    virtual ~Game();
};

} // namespace isopunk

#endif // GAME_H
