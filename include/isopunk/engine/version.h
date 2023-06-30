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

/// @brief Software version structure.
struct Version {
    std::uint32_t major;
    std::uint32_t minor;
    std::uint32_t patch;

    /// @brief Generates a Vulkan API version.
    ///
    /// @return Vulkan API version.
    std::uint32_t mk_vk_api_version() const
    {
        return VK_MAKE_API_VERSION(0, major, minor, patch);
    }
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_VERSION_H
