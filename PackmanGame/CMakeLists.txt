cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_FLAGS "-lGL")


set(GLEW_INCLUDE_PATH "/home/alex/Dev/Librarires/glew-2.1.0/include")
set(GLFW_INCLUDE_PATH "/home/alex/Dev/Librarires/glfw-3.3.2/include")
set(BOOST_INCLUDE_PATH "/home/alex/Dev/Librarires/boost_1_72_0")

set(GLEW_LIB_PATH "/home/alex/Dev/Librarires/glew-2.1.0/lib")
set(GLFW_LIB_PATH "/home/alex/Dev/Librarires/glfw_build/src")
set(BOOST_LIB_PATH "/home/alex/Dev/Librarires/boost_1_72_0/stage/lib")

include_directories(${GLEW_INCLUDE_PATH} ${GLFW_INCLUDE_PATH} ${BOOST_INCLUDE_PATH})
link_directories(${GLEW_LIB_PATH} ${GLFW_LIB_PATH} ${BOOST_LIB_PATH})

find_package(OpenGL REQUIRED)
set(OpenGL_GL_REFERENCE "GLVND")

set(src "main.cpp" "Shader.cpp")

add_executable (PackmanGame ${src})

target_link_libraries(PackmanGame ${OPENGL_LIBRARIES} glfw GLEW boost_filesystem)