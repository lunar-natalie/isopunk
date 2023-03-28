// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file utils.h
/// @brief Miscellaneous engine utility functions.

#ifndef ISOPUNK_ENGINE_UTILS_H
#define ISOPUNK_ENGINE_UTILS_H

#include <stdexcept>

#include <SDL2/SDL.h>

namespace isopunk {

/// @brief Throws an exception with the specified message if the condition is
/// `false`.
///
/// @param condition Condition to assert as `true`.
/// @param message Exception message string.
///
/// @throw std::runtime_error
inline void runtime_assert(bool condition, const char* message)
{
    if (!condition) {
        throw std::runtime_error(message);
    }
}

/// @brief Throws an exception with the last SDL error message string if the
/// condition is `false`.
///
/// @param condition Condition to assert as `true`.
///
/// @throw std::runtime_error
inline void sdl_assert(bool condition)
{
    if (!condition) {
        throw std::runtime_error(SDL_GetError());
    }
}

/// @brief Throws an `std::runtime_error` with the last SDL error message if the
/// condition is `SDL_FALSE`.
///
/// @param condition Condition to assert as `SDL_TRUE`.
///
/// @throw std::runtime_error
inline void sdl_assert(SDL_bool condition)
{
    if (condition == SDL_FALSE) {
        throw std::runtime_error(SDL_GetError());
    }
}

} // namespace isopunk

#endif // ISOPUNK_ENGINE_UTILS_H
