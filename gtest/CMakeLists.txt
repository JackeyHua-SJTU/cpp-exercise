cmake_minimum_required(VERSION 3.26)
project(gtest)
# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(ROOT_DIR ${CMAKE_SOURCE_DIR})

# header file directory, explicit tell the path of header files
# 头文件路径，用于src文件夹下头文件路径的解析
include_directories(include ${ROOT_DIR}/googletest/googletest/include)

# Add directories in which the linker will look for libraries.
# 连接阶段所需的文件所在的路径
link_directories(${ROOT_DIR}/googletest/build/lib)

# assign DIR_SRCS (a variable) to all .cpp and .c (source) files in src directory
# will not recursively find sub-directories
aux_source_directory(src DIR_SRCS)

# All source files that needs to be compiled
# only 1 main function is allowed
add_executable(gtest src/student.cpp src/gtest_fixture.cpp)

# Link libraries
# 将libgtest.a libgtest_main.a链接到gtest
target_link_libraries(gtest libgtest.a libgtest_main.a)

# Execution of CMake
# mkdir build
# cd build
# cmake .. (where CMakeLists.txt is located)
# make (execute makefile)

