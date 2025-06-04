#include <gtest/gtest.h>
#include "core/post/PostProcessor.h"
#include <fstream>
#include <string>
#include <cstdio>

TEST(PostProcessor, LoadInvalidTemplate) {
    Post::PostProcessor p;
    EXPECT_FALSE(p.loadTemplate("nonexistent.lua"));
}

TEST(PostProcessor, ProcessFileCopy) {
    Post::PostProcessor p;
    std::string tpl = std::string(SOURCE_DIR) + "/LICENSE";
    EXPECT_TRUE(p.loadTemplate(tpl));

    const char* in = "post_in.gcode";
    const char* out = "post_out.gcode";

    {
        std::ofstream f(in);
        f << "G0 X0 Y0\n";
    }
    EXPECT_TRUE(p.processFile(in, out));
    std::remove(in);
    std::remove(out);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
