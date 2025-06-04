#pragma once

#include <string>

namespace Post {

class PostProcessor {
public:
    PostProcessor();

    // Load configuration script or template describing the target controller.
    // Currently it only records the path; future versions will parse a Lua
    // script or dedicated DSL.
    bool loadTemplate(const std::string& path);

    // Convert generic G-code into controller specific output.
    bool processFile(const std::string& input, const std::string& output) const;

private:
    std::string templatePath_;
};

} // namespace Post
