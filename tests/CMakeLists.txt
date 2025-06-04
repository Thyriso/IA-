find_package(GTest REQUIRED)

add_executable(geometry_tests geometry_tests.cpp)
target_link_libraries(geometry_tests PRIVATE geometry GTest::gtest_main)
add_test(NAME geometry_tests COMMAND geometry_tests)

add_executable(toolpath_tests toolpath_tests.cpp)
target_link_libraries(toolpath_tests PRIVATE toolpath GTest::gtest_main)
add_test(NAME toolpath_tests COMMAND toolpath_tests)

add_executable(post_tests post_tests.cpp)
target_link_libraries(post_tests PRIVATE post GTest::gtest_main)
target_compile_definitions(post_tests PRIVATE SOURCE_DIR="${CMAKE_SOURCE_DIR}")
add_test(NAME post_tests COMMAND post_tests)
