#pragma once

#include <string>
#include <vector>

namespace Plugin {

class IPlugin;

class PluginManager {
public:
    // Load a plugin library and instantiate it. On Qt platforms QPluginLoader
    // can be used; here we rely on dlopen/dlsym.
    bool load(const std::string& path);

    const std::vector<IPlugin*>& plugins() const;

private:
    std::vector<IPlugin*> plugins_;
    std::vector<void*> handles_;
};

} // namespace Plugin
