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

/// @brief Main game class.
///
/// Implements the IsoPunk Engine API.
///
/// @headerfile game.h "game.h"
class Game : Engine {
public:
    /// @brief Constructs the game object.
    ///
    /// Initializes the engine and sets up the initial drawable objects.
    Game();

    /// @brief Destructs the game object.
    ///
    /// Deinitializes the game and stops the engine runtime.
    virtual ~Game();

    /// @brief Starts the game.
    ///
    /// Sets up and starts the engine runtime using objects generated by the
    /// game.
    virtual void start();
};

} // namespace isopunk

#endif // GAME_H
