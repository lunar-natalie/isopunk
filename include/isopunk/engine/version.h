// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file version.h
/// @brief Software version structure.

#ifndef ISOPUNK_ENGINE_VERSION_H
#define ISOPUNK_ENGINE_VERSION_H

#include <cstdint>

#include <vulkan/vulkan.hpp>

namespace isopunk {

/// @brief Software version information.
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

} // namespace isopunk

#endif // ISOPUNK_ENGINE_VERSION_H
