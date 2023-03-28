// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file engine.h
/// @brief Main include file for the IsoPunk Engine class.

#ifndef ISOPUNK_ENGINE_H
#define ISOPUNK_ENGINE_H

#include <cstdint>
#include <vector>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.hpp>

#include <isopunk/engine/config.h>
#include <isopunk/engine/window.h>

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
    Engine(EngineConfig config = default_config);

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

    /// @brief Configuration for setting up the engine.
    EngineConfig config;

    /// @brief Default init configuration.
    static const EngineConfig default_config;

    /// @brief Vulkan instance.
    ///
    /// Drawable objects can access this instance in order to render using the
    /// Vulkan API.
    vk::Instance vk_instance;

private:
    /// @brief Renders all objects within the main loop.
    void draw();

    /// @brief Initializes the Vulkan API.
    ///
    /// @throw std::runtime_error if a fatal error occurs in the initialization
    /// process.
    void vk_init();

    /// @brief Deinitializes the Vulkan API.
    void vk_deinit() const noexcept;

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
    /// @throw std::runtime_error if a fatal error occurs in the initialization
    /// process.
    ///
    /// @see Engine::instance
    void vk_create_instance();

    /// @brief Creates the Vulkan window surface.
    ///
    /// @throw std::runtime_error if a fatal error occurs in the initialization
    /// process.
    void vk_create_surface();

    /// @brief Gets available Vulkan physical devices.
    ///
    /// @throw std::runtime_error if no devices are found.
    ///
    /// @see Engine::physical_devices
    /// @see Engine::physical_device
    void vk_get_physical_devices();

    /// @brief Creates the Vulkan rendering device.
    ///
    /// @throw std::runtime_error if no devices are found.
    ///
    /// @see Engine::device
    void vk_create_device();

    /// @brief Main graphical window.
    Window* window;

    /// @brief Main rendering surface, attached to the main window.
    vk::SurfaceKHR vk_surface;

    /// @brief Vulkan physical devices.
    std::vector<vk::PhysicalDevice> vk_physical_devices;

    /// @brief Primary Vulkan physical device.
    vk::PhysicalDevice vk_physical_device;

    /// @brief Vulkan rendering device.
    vk::Device vk_device;

    /// @brief Enabled global Vulkan instance extension names.
    std::vector<const char*> vk_extensions;

    /// @brief Enabled Vulkan validation layer names.
    std::vector<const char*> vk_layers;

    /// @brief Holds the index of each available Vulkan queue family.
    struct QueueFamilyIndices {
        std::uint32_t graphics;
        std::uint32_t present;
    } vk_queue_family_indices;

    /// @brief Vulkan queue objects for each available queue family.
    struct Queues {
        vk::Queue graphics;
        vk::Queue present;
    } vk_queues;
};

} // namespace isopunk

#endif // ISOPUNK_ENGINE_H
