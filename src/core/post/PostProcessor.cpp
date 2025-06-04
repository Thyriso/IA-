#include "PostProcessor.h"
#include <fstream>

namespace Post {

PostProcessor::PostProcessor() = default;

bool PostProcessor::loadTemplate(const std::string& path) {
    std::ifstream f(path);
    if (!f.good())
        return false;
    templatePath_ = path;
    return true;
}

bool PostProcessor::processFile(const std::string& input, const std::string& output) const {
    std::ifstream in(input);
    if (!in) {
        return false;
    }
    std::ofstream out(output);
    if (!out) {
        return false;
    }
    // For now simply copy the file. Future versions will apply the template
    // stored in `templatePath_` to transform the G-code.
    out << in.rdbuf();
    return true;
}

} // namespace Post
