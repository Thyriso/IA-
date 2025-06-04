add_library(post STATIC PostProcessor.cpp)
target_include_directories(post PUBLIC ${CMAKE_SOURCE_DIR}/src)
