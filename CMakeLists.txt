cmake_minimum_required(VERSION 3.10.2)
project(wlin_client)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS ON)

find_package (Threads)
find_package(Boost REQUIRED system)

include_directories(${Boost_INCLUDE_DIR})


add_executable(wlin_client main.cpp Application.cpp Application.h
        LinuxStatus/Linuxstatus.cpp LinuxStatus/Linuxstatus.h StatusJSON/LsJson.cpp StatusJSON/LsJson.h)

target_link_libraries (wlin_client ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wlin_client  ${Boost_LIBRARIES})