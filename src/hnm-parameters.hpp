/*
    Rocaloid
    Copyright (C) 2015 StarBrilliant <m13253@hotmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not,
    see <http://www.gnu.org/licenses/>.
*/

#ifndef RUCE_HNM_PARAMETERS_HPP
#define RUCE_HNM_PARAMETERS_HPP

#include <cstdint>
#include <vector>
#include "utils.hpp"
#include "wrapped-angle.hpp"

namespace RUCE {

class HNMParameters {
public:
    ssize_t analysis_window_size;
    ssize_t analysis_window_hop;
    static const size_t max_pillars = 128;
    /**
     * The middle point of the first analysis window
     */
    ssize_t first_window_mid;
    /**
     * The first index is window index,
     * the second index is harmony index.
     */
    std::vector<std::array<double, max_pillars>> harmony_frequencies;
    std::vector<std::array<double, max_pillars>> harmony_magnitude;
    std::vector<std::array<WrappedAngle, max_pillars>> harmony_phase;
    double frame_to_window_idx(ssize_t frame_idx) const {
        return double(frame_idx-first_window_mid) / double(analysis_window_hop);
    }
    double frame_to_window_idx(double frame_idx) const {
        return (frame_idx-first_window_mid) / double(analysis_window_hop);
    }
    ssize_t window_to_frame_idx(double window_idx) const {
        return ssize_t(std::round(window_idx*analysis_window_hop)) + first_window_mid;
    }
};

}

#endif