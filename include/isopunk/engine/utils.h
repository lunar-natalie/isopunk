// This header is part of the ipkengine API.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ISOPUNK_ENGINE_UTILS_H
#define ISOPUNK_ENGINE_UTILS_H

#include <stdexcept>

#include <SDL2/SDL.h>

namespace isopunk {

/// @brief Throws an `std::runtime_error` with the last SDL error message if the
/// condition is `false`.
/// @param condition Condition to assert as `true`.
inline void sdl_assert(bool condition)
{
    if (!condition) {
        throw std::runtime_error(SDL_GetError());
    }
}

/// @brief Throws an `std::runtime_error` with the last SDL error message if the
/// condition is `SDL_FALSE`.
/// @param condition Condition to assert as `SDL_TRUE`.
inline void sdl_assert(SDL_bool condition)
{
    if (condition == SDL_FALSE) {
        throw std::runtime_error(SDL_GetError());
    }
}

} // namespace isopunk

#endif // ISOPUNK_ENGINE_UTILS_H
