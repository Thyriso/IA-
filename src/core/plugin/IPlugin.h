#pragma once

namespace Plugin {

class IPlugin {
public:
    virtual ~IPlugin() = default;

    virtual const char* name() const = 0;
    virtual bool initialize() = 0;
    virtual void shutdown() = 0;
};

} // namespace Plugin
