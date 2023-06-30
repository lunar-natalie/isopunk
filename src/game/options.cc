// IsoPunk
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file options.cc
/// @brief Program options utilities.

#include "options.h"

#include <filesystem>
#include <memory>
#include <sstream>

using namespace isopunk;

namespace fs = std::filesystem;

Options::Options(int argc, const char* const* argv)
    : ac{argc},
      av{argv}
{
    basename = fs::path(av[0]).stem().string();
    std::stringstream desc_ss;
    desc_ss << "Usage: " << basename << " [OPTION]...\n"
            << "A cross-platform isometric turn-based strategy game with a "
               "cyberpunk theme.\n"
            << "\n"
            << "Mandatory arguemtns to long options are mandatory for short "
               "options too";
    desc = std::make_unique<opt::options_description>(desc_ss.str());
}

std::shared_ptr<opt::variables_map>& Options::parse_args()
{
    opt::variables_map vm;
    opt::store(opt::parse_command_line(ac, av, *desc), vm);
    opt::notify(vm);
    this->vm = std::make_shared<opt::variables_map>(vm);
    return this->vm;
}
