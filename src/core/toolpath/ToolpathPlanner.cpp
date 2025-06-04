#include "ToolpathPlanner.h"
#include <fstream>

namespace Toolpath {

ToolpathPlanner::ToolpathPlanner() = default;

bool ToolpathPlanner::generateContour2D(const std::vector<std::pair<double, double>>& polygon) {
    if (polygon.empty()) {
        return false;
    }
    path_ = polygon;
    return true;
}

bool ToolpathPlanner::exportGCode(const std::string& file) const {
    if (path_.empty()) {
        return false;
    }
    std::ofstream out(file);
    if (!out) {
        return false;
    }
    out << "G21\n"; // metric
    out << "G90\n"; // absolute
    auto start = path_.front();
    out << "G0 X" << start.first << " Y" << start.second << "\n";
    for (size_t i = 1; i < path_.size(); ++i) {
        out << "G1 X" << path_[i].first << " Y" << path_[i].second << "\n";
    }
    out << "M30\n";
    return true;
}

} // namespace Toolpath


