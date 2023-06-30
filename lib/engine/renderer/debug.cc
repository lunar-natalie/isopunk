// ipkengine
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file debug.cc
/// @brief Vulkan debug message handlers.

#include <isopunk/engine/renderer.h>

#include <iostream>
#include <memory>

#include <vulkan/vulkan.hpp>

#include <isopunk/engine/rdef.h>

using namespace isopunk;

// Copyright(c) 2019, NVIDIA CORPORATION. All rights reserved.
// Copyright(c) 2023, Natalie Wiggins.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
VKAPI_ATTR VkBool32 VKAPI_CALL Renderer::debug_messenger_callback(
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    VkDebugUtilsMessengerCallbackDataEXT const* pCallbackData,
    void* /*pUserData*/)
{

    if (pCallbackData->messageIdNumber == 648835635) {
        // UNASSIGNED-khronos-Validation-debug-build-warning-message
        return VK_FALSE;
    }
    if (pCallbackData->messageIdNumber == 767975156) {
        // UNASSIGNED-BestPractices-vkCreateInstance-specialuse-extension
        return VK_FALSE;
    }

    std::ostream& log = std::cerr;

    log << vk::to_string(
        static_cast<vk::DebugUtilsMessageTypeFlagsEXT>(messageTypes))
        << ":\n";
    log << std::string("\t") << "messageIDName   = <"
        << pCallbackData->pMessageIdName << ">\n";
    log << std::string("\t")
        << "messageIdNumber = " << pCallbackData->messageIdNumber << "\n";
    log << std::string("\t") << "message         = <" << pCallbackData->pMessage
        << ">\n";
    if (0 < pCallbackData->queueLabelCount) {
        log << std::string("\t") << "Queue Labels:\n";
        for (uint32_t i = 0; i < pCallbackData->queueLabelCount; i++) {
            log << std::string("\t\t") << "labelName = <"
                << pCallbackData->pQueueLabels[i].pLabelName << ">\n";
        }
    }
    if (0 < pCallbackData->cmdBufLabelCount) {
        log << std::string("\t") << "CommandBuffer Labels:\n";
        for (uint32_t i = 0; i < pCallbackData->cmdBufLabelCount; i++) {
            log << std::string("\t\t") << "labelName = <"
                << pCallbackData->pCmdBufLabels[i].pLabelName << ">\n";
        }
    }
    if (0 < pCallbackData->objectCount) {
        log << std::string("\t") << "Objects:\n";
        for (uint32_t i = 0; i < pCallbackData->objectCount; i++) {
            log << std::string("\t\t") << "Object " << i << "\n";
            log << std::string("\t\t\t") << "objectType   = "
                << vk::to_string(static_cast<vk::ObjectType>(
                       pCallbackData->pObjects[i].objectType))
                << "\n";
            log << std::string("\t\t\t")
                << "objectHandle = " << pCallbackData->pObjects[i].objectHandle
                << "\n";
            if (pCallbackData->pObjects[i].pObjectName) {
                log << std::string("\t\t\t") << "objectName   = <"
                    << pCallbackData->pObjects[i].pObjectName << ">\n";
            }
        }
    }
    return VK_TRUE;
}

vkptr::DebugUtilsMessengerEXT
Renderer::create_debug_messenger(vkptr::Instance& inst)
{
    vk::DebugUtilsMessageSeverityFlagsEXT severity_flags(
        vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning
        | vk::DebugUtilsMessageSeverityFlagBitsEXT::eError);
    vk::DebugUtilsMessageTypeFlagsEXT message_type_flags(
        vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral
        | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance
        | vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation);
    vk::DebugUtilsMessengerCreateInfoEXT create_info{
        .flags           = {},
        .messageSeverity = severity_flags,
        .messageType     = message_type_flags,
        .pfnUserCallback = &debug_messenger_callback};
    return std::make_unique<vkr::DebugUtilsMessengerEXT>(*inst, create_info);
}
