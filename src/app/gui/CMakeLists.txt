set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets OpenGL REQUIRED)

add_executable(faogui
    main_gui.cpp
    MainWindow.cpp
    ViewerWidget.cpp
    SimulationOverlay.cpp
)

target_include_directories(faogui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(faogui PRIVATE geometry Qt6::Widgets Qt6::OpenGL)

