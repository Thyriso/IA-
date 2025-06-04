#include "Simulator.h"
#include <fstream>
#include <sstream>


namespace Simulation {

Simulator::Simulator() = default;

bool Simulator::loadToolpath(const char* path) {
    std::ifstream f(path);
    if (!f.good()) {
        return false;
    }
    path_.clear();
    std::string line;
    while (std::getline(f, line)) {
        std::istringstream iss(line);
        char c;
        double x=0, y=0;
        while (iss >> c) {
            if (c == 'X') {
                iss >> x;
            } else if (c == 'Y') {
                iss >> y;
            }
        }
        if (!line.empty()) {
            path_.emplace_back(x, y);
        }
    }
    return true;
}

bool Simulator::run() {
    for (const auto& pt : path_) {
        if (pt.first < workArea_[0] || pt.first > workArea_[2] ||
            pt.second < workArea_[1] || pt.second > workArea_[3]) {
            return false; // collision with bounds
        }
    }
    return true;
}

} // namespace Simulation
