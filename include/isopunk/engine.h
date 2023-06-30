// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file engine.h
/// @brief Declares the main class for ipkengine.

#ifndef ISOPUNK_ENGINE_H
#define ISOPUNK_ENGINE_H

#include <memory>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/renderer.h>
#include <isopunk/engine/window.h>

namespace isopunk {

/// @brief IsoPunk engine class.
///
/// Provides a graphical application runtime. Derived classes should publicly
/// inherit this class.
class Engine {
protected:
    /// @brief Initializes an engine instance.
    ///
    /// @param conf Configuration properties.
    ///
    /// @throw std::runtime_error The engine has encountered a critical error
    /// and the application should be terminated.
    Engine(EngineConfig const conf = default_conf);

public:
    /// @brief Deinitializes the engine.
    virtual ~Engine() noexcept;

    /// @brief Starts the main event loop.
    void start();

protected:
    const EngineConfig        conf;
    static const EngineConfig default_conf;

    std::unique_ptr<Window> wnd;

private:
    std::unique_ptr<Renderer> renderer;

    /// @brief Draws graphical engine objects per frame in the main event loop
    /// defined by both the engine and the implementation via the renderer.
    void draw();
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_H
