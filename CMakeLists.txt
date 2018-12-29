cmake_minimum_required(VERSION 3.13)
project(Priority_Scheduling_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Priority_Scheduling_System main.cpp Process.cpp Process.h Heap.cpp Heap.h)