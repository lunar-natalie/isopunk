// This header is part of the ipkengine API.
//
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ISOPUNK_ENGINE_CONFIG_H
#define ISOPUNK_ENGINE_CONFIG_H

#include <cstdint>
#include <string>

#include <vulkan/vulkan.hpp>

namespace isopunk {

/// @brief Engine configuration.
///
/// Contains properties used to set up the engine. These properties are used to
/// set up the graphical context and may be dynamically loaded by the game
/// implementation.
struct EngineConfig {
    /// @brief Name of the application to provide to the graphics API and to be
    /// used as the title of the main window.
    std::string application_name;

    /// @brief Software version.
    struct Version {
        /// @brief Major version number.
        uint32_t major;

        /// @brief Minor version number.
        uint32_t minor;

        /// @brief Patch version number.
        uint32_t patch;

        /// @brief Generates a Vulkan API version from the version numbers in
        /// the object.
        ///
        /// @return Vulkan API version value.
        uint32_t vk_make_api_version() const
        {
            return VK_MAKE_API_VERSION(0, major, minor, patch);
        }
    };

    /// @brief Application version.
    Version application_version;

    /// @brief Initial width of the main window.
    uint32_t window_width;

    /// @brief Initial height of the main window.
    uint32_t window_height;

    /// @brief Default engine configuration.
    static const EngineConfig default_config;
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_CONFIG_H
