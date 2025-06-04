#include <iostream>
#include <cxxopts.hpp>
#include <vector>
#include <utility>
#include "core/geometry/Kernel.h"
#include "core/toolpath/ToolpathPlanner.h"

int main(int argc, char** argv) {
    cxxopts::Options options("faocli", "CAM command line interface");
    options.add_options()
        ("i,input", "Input CAD file", cxxopts::value<std::string>())
        ("g,generate", "Generate G-code", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Show help");

    auto result = options.parse(argc, argv);

    if (result.count("help") || argc == 1) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    Geometry::Kernel kernel;

    if (result.count("input")) {
        if (!kernel.loadModel(result["input"].as<std::string>().c_str())) {
            std::cerr << "Failed to load model\n";
            return 1;
        }

        auto box = kernel.getBoundingBox();
        std::cout << "Model loaded. Bounding box: ["
                  << box.minX << ", " << box.minY << ", " << box.minZ << "] - ["
                  << box.maxX << ", " << box.maxY << ", " << box.maxZ << "]\n";
    }

    if (result["generate"].as<bool>()) {
        Toolpath::ToolpathPlanner planner;

        auto box = kernel.getBoundingBox();
        std::vector<std::pair<double, double>> poly = {
            {box.minX, box.minY},
            {box.maxX, box.minY},
            {box.maxX, box.maxY},
            {box.minX, box.maxY},
            {box.minX, box.minY}
        };

        if (!planner.generateContour2D(poly) ||
            !planner.exportGCode("output.gcode")) {
            std::cerr << "Failed to generate G-code\n";
            return 1;
        }

        std::cout << "G-code written to output.gcode\n";
    }

    return 0;
}

