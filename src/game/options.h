// IsoPunk
// Copyright (c) 2023 Natalie Wiggins <islifepeachy@outlook.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later

/// @file options.h
/// @brief Program options header.

#ifndef OPTIONS_H
#define OPTIONS_H

#include <boost/program_options.hpp>

namespace isopunk {

namespace opt = boost::program_options;

class Options {
public:
    Options(int argc, const char* const* argv);

    std::unique_ptr<opt::options_description> desc;
    std::shared_ptr<opt::variables_map>       vm;

    std::shared_ptr<opt::variables_map>& parse_args();

private:
    int                ac;
    const char* const* av;
};

} // namespace isopunk

#endif // OPTIONS_H
