#include <gtest/gtest.h>
#include "core/geometry/Kernel.h"

TEST(GeometryKernel, LoadInvalidModel) {
    Geometry::Kernel k;
    EXPECT_FALSE(k.loadModel("nonexistent.step"));
}

TEST(GeometryKernel, DefaultBoundingBox) {
    Geometry::Kernel k;
    auto box = k.getBoundingBox();
    EXPECT_DOUBLE_EQ(box.minX, 0.0);
    EXPECT_DOUBLE_EQ(box.maxZ, 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
