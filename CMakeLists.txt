cmake_minimum_required(VERSION 3.23)
project(clo_implementation)

set(CMAKE_CXX_STANDARD 17)

add_executable(clo_implementation main.cpp models/Order.cpp models/Order.h models/Limit.cpp models/Limit.h models/Entry.cpp models/Entry.h book/CLO.cpp book/CLO.h models/Trade.cpp models/Trade.h engine/Engine.cpp engine/Engine.h)
