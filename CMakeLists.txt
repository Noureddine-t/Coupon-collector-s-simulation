cmake_minimum_required(VERSION 3.26)
project(Coupon-collector-s-simulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(Coupon-collector-s-simulation main.cpp Functions.h
        main4.cpp)
add_executable(Main2 main2.cpp Functions.h)
add_executable(Main3 main3.cpp Functions.h)
add_executable(Main4 main4.cpp Functions.h)