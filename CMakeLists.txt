cmake_minimum_required(VERSION 3.5)
project(Project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TreeNode.h LinkedTree.h Heap.h AVLTree.h)
add_executable(Project3 ${SOURCE_FILES})