// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file engine.h
/// @brief Declares the main class for ipkengine.

#ifndef ISOPUNK_ENGINE_H
#define ISOPUNK_ENGINE_H

#include <cstdint>
#include <vector>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/window.h>

namespace isopunk {

class Engine {
protected:
    Engine(EngineConfig config = default_config);

public:
    virtual ~Engine() noexcept;
    void start();

protected:
    const EngineConfig config;
    static const EngineConfig default_config;
    Window* window;

private:
    void draw();
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_H
