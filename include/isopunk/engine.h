// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file engine.h
/// @brief Main include file for the IsoPunk Engine class.

#ifndef ISOPUNK_ENGINE_H
#define ISOPUNK_ENGINE_H

#include <vector>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/config.h>

namespace isopunk {

/// @brief IsoPunk game engine.
///
/// This class provides an abstracted framework to initialize the graphical
/// environment for the game, render the UI and game objects, perform generic
/// logic operations and deinitialize the envrionment when the derived instance
/// is destroyed.
///
/// The program's game class should privately inherit from this class and
/// implement its virtual methods. The game class must implement its own
/// constructor and destructor which call the respective constructor and
/// destructor of this base class to initialize and deinitialize the engine.
///
/// To run the game, the game class should be constructed before calling its
/// `start` method. These core methods, among other virtual and non-virtual
/// engine methods may throw an exception. The program's main function should
/// catch exceptions of type `std::runtime_error` and log the error before
/// stopping execution when caught.
class Engine {

    ////////////////////////////////////////////////////////////////////////////
    // Interface ///////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

protected:
    /// @brief Constructs the engine object.
    ///
    /// Initializes internal engine properties.
    ///
    /// This method should be called first in the constructor of the derived
    /// game class.
    ///
    /// @param config Configuration properties.
    Engine(EngineConfig config = EngineConfig::default_config);

public:
    /// @brief Destructs the engine object.
    ///
    /// This method should be implemented by the derived game class to
    /// deinitialize the game and engine internals.
    ///
    /// @see Engine::terminate
    virtual ~Engine() = default;

    /// @brief Starts the game.
    ///
    /// This method should be implemented by the derived game class to
    /// initialize and start the engine runtime.
    ///
    /// @throw std::runtime_error if a fatal error occurs in the engine runtime.
    virtual void start() = 0;

    ////////////////////////////////////////////////////////////////////////////
    // Runtime methods /////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

protected:
    /// @brief Creates the program's main window and populates engine internals
    /// using the objects provided by the game implementation.
    ///
    /// @throw std::runtime_error if a fatal error occurs in the initialization
    /// process.
    void init();

    /// @brief Starts the engine runtime, running the main window loop to
    /// continuously draw all current objects into the window.
    void run();

    /// @brief Stops the engine runtime.
    ///
    /// This method should be called in the destructor of the derived game class
    /// to implicitly deinitialize engine internals and frameworks when the
    /// instance goes out of scope or the program itself is terminated.
    void terminate() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    // Protected properties ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Configuration for setting up the engine.
    EngineConfig config;

    /// @brief Vulkan instance.
    ///
    /// Drawable objects can access this instance in order to render using the
    /// Vulkan API.
    vk::Instance vk_instance;

    ////////////////////////////////////////////////////////////////////////////
    // Internal methods ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

private:
    /// @brief Initializes the Vulkan API.
    ///
    /// @throw std::runtime_error if a fatal error occurs in the initialization
    /// process.
    void vk_init();

    /// @brief Gets the available Vulkan instance extensions.
    ///
    /// @see Engine::extensions
    void vk_get_instance_extensions();

    /// @brief Creates the Vulkan instance, using application info derived from
    /// the engine configuration.
    ///
    /// This method must be called before accessing the instance for executing
    /// Vulkan commands.
    ///
    /// @see Engine::vk_instance
    ///
    /// @throw std::runtime_error if a fatal error occurs in the initialization
    /// process.
    void vk_create_instance();

    /// @brief Deinitializes the Vulkan API.
    void vk_deinit() const noexcept;

    /// @brief Renders all objects within the main loop.
    void draw();

    ////////////////////////////////////////////////////////////////////////////
    // Internal properties /////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Main graphical window used as the primary rendering surface.
    SDL_Window* window;

    /// @brief Window height and width in pixels.
    vk::Extent2D window_extent;

    /// @brief Enabled global Vulkan instance extension names.
    std::vector<const char*> extensions;

    /// @brief Enabled Vulkan validation layer names.
    std::vector<const char*> layers;
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_H
