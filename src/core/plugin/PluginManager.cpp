#include "PluginManager.h"
#include "IPlugin.h"
#include <dlfcn.h>

namespace Plugin {

bool PluginManager::load(const std::string& path) {
    void* handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        return false;
    }
    using CreateFunc = IPlugin* (*)();
    auto create = reinterpret_cast<CreateFunc>(dlsym(handle, "createPlugin"));
    if (!create) {
        dlclose(handle);
        return false;
    }
    IPlugin* plugin = create();
    if (!plugin || !plugin->initialize()) {
        dlclose(handle);
        return false;
    }
    plugins_.push_back(plugin);
    handles_.push_back(handle);
    return true;
}

const std::vector<IPlugin*>& PluginManager::plugins() const {
    return plugins_;
}

} // namespace Plugin
