find_package(cxxopts REQUIRED)
add_executable(faocli cli_main.cpp)
target_link_libraries(faocli PRIVATE geometry toolpath cxxopts::cxxopts)

if(ENABLE_GUI)
    add_subdirectory(gui)
endif()

