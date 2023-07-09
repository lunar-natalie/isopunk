// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file utils.h
/// @brief Miscellaneous utility function definitions for ipkengine.

#ifndef ISOPUNK_ENGINE_UTILS_H
#define ISOPUNK_ENGINE_UTILS_H

#include <stdexcept>

#include <SDL2/SDL.h>

namespace isopunk {

/// @brief Assert a condition at runtime.
///
/// @param cond Boolean condition.
/// @param msg Message string.
///
/// @throw std::runtime_error The asserted condition was false. The exception
/// argument will contain the provided error message.
inline void runtime_assert(bool cond, const char* msg)
{
    if (!cond) {
        throw std::runtime_error(msg);
    }
}

/// @brief Assert the result of an SDL routine at runtime.
///
/// @param res Boolean condition.
///
/// @throw std::runtime_error The asserted condition was false. The exception
/// argument will contain a message corresponding the last error that occurred
/// on the current thread.
inline void sdl_assert(bool cond)
{
    if (!cond) {
        throw std::runtime_error(SDL_GetError());
    }
}

/// @brief Assert the result of an SDL routine at runtime.
///
/// @param res SDL_bool condition.
///
/// @throw std::runtime_error The asserted condition was false. The exception
/// argument will contain a message corresponding the last error that occurred
/// on the current thread.
inline void sdl_assert(SDL_bool cond)
{
    if (cond == SDL_FALSE) {
        throw std::runtime_error(SDL_GetError());
    }
}

} // namespace isopunk

#endif // ISOPUNK_ENGINE_UTILS_H
