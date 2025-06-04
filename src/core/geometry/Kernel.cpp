#include "Kernel.h"

#include <fstream>
#include <filesystem>
#include <limits>

namespace fs = std::filesystem;

namespace Geometry {

Kernel::Kernel() {
    // Placeholder constructor. Real initialization will setup OpenCascade
    // resources when integrated.
}

bool Kernel::loadModel(const char* filepath) {
    std::ifstream f(filepath);
    if (!f.good()) {
        return false;
    }
    bbox_ = BoundingBox{};
    std::string word;
    double minX = std::numeric_limits<double>::max();
    double minY = std::numeric_limits<double>::max();
    double minZ = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::lowest();
    double maxY = std::numeric_limits<double>::lowest();
    double maxZ = std::numeric_limits<double>::lowest();

    while (f >> word) {
        if (word == "vertex") {
            double x,y,z; f >> x >> y >> z;
            minX = std::min(minX, x); maxX = std::max(maxX, x);
            minY = std::min(minY, y); maxY = std::max(maxY, y);
            minZ = std::min(minZ, z); maxZ = std::max(maxZ, z);
        }
    }

    if (minX == std::numeric_limits<double>::max()) {
        bbox_ = BoundingBox{}; // file had no vertices
    } else {
        bbox_ = {minX,minY,minZ,maxX,maxY,maxZ};
    }
    return true;
}

Kernel::BoundingBox Kernel::getBoundingBox() const {
    return bbox_;
}

} // namespace Geometry

