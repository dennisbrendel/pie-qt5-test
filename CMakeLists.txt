cmake_minimum_required(VERSION 3.13.0)

project(qt5_pie)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -std=c++14")

set(CMAKE_AUTOMOC ON)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL Intel)
  set(Qt5_HINTS_DIRS /p/hpc/psp/Qt/Qt-5.12.0-icc-19.0)
else()
  set(Qt5_HINTS_DIRS /p/hpc/psp/Qt/Qt-5.12.0-gcc-8.3.1)
endif()
find_package(Qt5 5.12 NO_MODULE COMPONENTS Widgets REQUIRED HINTS ${Qt5_HINTS_DIRS})

add_executable(qt5_pie main.cpp MainWnd.cpp)
add_executable(qt5_no-pie main.cpp MainWnd.cpp)
target_link_libraries(qt5_pie Qt5::Widgets)
target_link_libraries(qt5_no-pie Qt5::Widgets)
target_link_options(qt5_pie PRIVATE -pie)

