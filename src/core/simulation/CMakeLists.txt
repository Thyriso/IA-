add_library(simulation STATIC Simulator.cpp)
target_include_directories(simulation PUBLIC ${CMAKE_SOURCE_DIR}/src)
