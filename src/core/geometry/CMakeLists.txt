add_library(geometry STATIC Kernel.cpp)
target_include_directories(geometry PUBLIC ${CMAKE_SOURCE_DIR}/src)
