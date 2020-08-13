cmake_minimum_required(VERSION 3.2.0)

find_package(OpenCL REQUIRED)


include_directories(${OpenCL_INCLUDE_DIRS})

message(${OpenCL_LIBRARIES})
add_executable(main main.c)
target_link_libraries(main ${OpenCL_LIBRARIES} -lMaliOpenCL)
