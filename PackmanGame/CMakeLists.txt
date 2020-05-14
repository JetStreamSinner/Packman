cmake_minimum_required (VERSION 3.8)

set(CMAKE_AUTOMOC ON)
# if cmake cannot found qt5widgets package than set path explicit by following instruction
# set(Qt5Widgets_DIR )

find_package(Qt5Widgets CONFIG REQUIRED)
set(src "main.cpp" "MainWindow.cpp" "SceneView.cpp" "GameModel.cpp" "Vertex.h"
"SceneObjects/SceneBound.cpp")

add_executable (PackmanGame ${src})
target_link_libraries(PackmanGame Qt5::Widgets)