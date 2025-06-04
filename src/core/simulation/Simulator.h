#pragma once
#include <vector>
#include <array>
#include <utility>

namespace Simulation {

class Simulator {
public:
    Simulator();

    // Load a toolpath file for simulation. The file is expected to be a G-code
    // text file containing X/Y moves which are sampled into a polyline.
    bool loadToolpath(const char* path);

    // Run a basic collision check and playback using a simple AABB test.
    bool run();

private:
    std::vector<std::pair<double,double>> path_;
    std::array<double,4> workArea_{0,0,1000,1000};
}; 

} // namespace Simulation
