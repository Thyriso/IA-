add_library(plugin STATIC PluginManager.cpp)
target_include_directories(plugin PUBLIC ${CMAKE_SOURCE_DIR}/src)
