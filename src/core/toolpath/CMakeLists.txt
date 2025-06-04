add_library(toolpath STATIC ToolpathPlanner.cpp)
target_include_directories(toolpath PUBLIC ${CMAKE_SOURCE_DIR}/src)
