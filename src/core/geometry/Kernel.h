#pragma once

namespace Geometry {

class Kernel {
public:
    struct BoundingBox {
        double minX{0};
        double minY{0};
        double minZ{0};
        double maxX{0};
        double maxY{0};
        double maxZ{0};
    };

    Kernel();

    // Loads a CAD model. For now only ASCII STL files are supported. When
    // OpenCascade becomes available this will handle STEP/IGES as well.
    bool loadModel(const char* filepath);

    // Returns the bounding box of the loaded model.
    BoundingBox getBoundingBox() const;

private:
    BoundingBox bbox_{};
};

} // namespace Geometry

