cmake_minimum_required(VERSION 3.2.0)

find_package(OpenCL REQUIRED)


include_directories(${OpenCL_INCLUDE_DIRS})

add_executable(main main.c)
target_link_libraries(main ${OpenCL_LIBRARIES})
