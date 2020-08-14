cmake_minimum_required(VERSION 3.2.0)

project(opengl_sdk)

find_package(glog REQUIRED)


# opengles version of fbo
# use glfw
add_executable(fbo_glfw ${CMAKE_CURRENT_SOURCE_DIR}/fbo_demo.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw_context.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/context_util.cc)
target_link_libraries(fbo_glfw -lGLESv2 -lglfw -lGL glog::glog)

# use egl
add_executable(fbo_egl ${CMAKE_CURRENT_SOURCE_DIR}/fbo_demo.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/egl_context.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/context_util.cc)
target_link_libraries(fbo_egl -lGLESv2 -lEGL -lGL glog::glog)
