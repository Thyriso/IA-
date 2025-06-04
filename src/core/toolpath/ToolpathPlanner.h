#pragma once

#include <string>
#include <vector>
#include <utility>

namespace Toolpath {

class ToolpathPlanner {
public:
    ToolpathPlanner();

    // Generate a contour from a polygon.
    // The algorithm is a naive copy until Clipper2 integration.
    bool generateContour2D(const std::vector<std::pair<double, double>>& polygon);

    // Export the generated path to a simple GRBL G-code file.
    bool exportGCode(const std::string& file) const;

private:
    std::vector<std::pair<double, double>> path_;
};

} // namespace Toolpath


