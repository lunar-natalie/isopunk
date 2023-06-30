// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file config.h
/// @brief Engine configuration.

#ifndef ISOPUNK_ENGINE_CONFIG_H
#define ISOPUNK_ENGINE_CONFIG_H

#include <cstdint>
#include <string>

#include <isopunk/engine/version.h>

namespace isopunk {

/// @brief Engine configuration attributes.
struct EngineConfig {
    std::string   app_name;      /// @brief Application name
    Version       app_version;   /// @brief Application version
    std::uint32_t window_width;  /// @brief Initial main window width
    std::uint32_t window_height; /// @brief Initial main window height
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_CONFIG_H
