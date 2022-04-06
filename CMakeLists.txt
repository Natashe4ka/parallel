cmake_minimum_required(VERSION 2.8)

project(third)

set(third_src main.cpp CIntN.cpp operators.cpp AT.cpp par.cpp)
set(third_hdr head.hpp CIntN.hpp AT.hpp CIntN0.hpp CIntN1.hpp factory.hpp)

add_executable(${PROJECT_NAME} ${third_src} ${third_hdr})

