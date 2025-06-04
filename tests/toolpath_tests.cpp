#include <gtest/gtest.h>
#include "core/toolpath/ToolpathPlanner.h"
#include <cstdio>

TEST(ToolpathPlanner, EmptyInput) {
    Toolpath::ToolpathPlanner p;
    EXPECT_FALSE(p.generateContour2D({}));
}

TEST(ToolpathPlanner, ExportGCode) {
    Toolpath::ToolpathPlanner p;
    std::vector<std::pair<double,double>> poly = {{0,0},{1,0},{1,1},{0,1},{0,0}};
    EXPECT_TRUE(p.generateContour2D(poly));
    const char* path = "test.gcode";
    EXPECT_TRUE(p.exportGCode(path));
    std::remove(path);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

