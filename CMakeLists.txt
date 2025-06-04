cmake_minimum_required(VERSION 3.20)
project(FAOProject LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_GUI "Build GUI application" OFF)
add_subdirectory(src)

option(ENABLE_TESTS "Build unit tests" OFF)
if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# CPack packaging configuration
set(CPACK_PACKAGE_NAME "FAOProject")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "TGZ;DEB;NSIS")
set(CPACK_PACKAGE_CONTACT "info@example.com")
include(CPack)

