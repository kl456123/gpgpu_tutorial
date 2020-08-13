cmake_minimum_required(VERSION 3.2.0)

project(opengl VERSION 1.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++14")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

find_package(OpenCV REQUIRED)
find_package(Glog REQUIRED)
find_package(glfw3 REQUIRED)

set(OpenGL_LIB -lglfw3 -pthread -lrt -lm -ldl)
#if(BUILD_ARM)
set(OpenGL_LIB ${OpenGL_LIB} -lGLESv2)
set(OpenGL_LIB ${OpenGL_LIB} -lEGL)
#else()
#    set(OpenGL_LIB ${OpenGL_LIB} -lGL)
#endif()

add_executable(demo demo.cc init.cc context.cc)

# use both in case anyone of them not found
target_link_libraries(demo ${OpenGL_LIB} ${GLOG_LIBRARIES})
