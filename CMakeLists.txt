cmake_minimum_required(VERSION 3.20)
project(ncurses_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src/")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(hello "${SRC_DIR}/hello.cpp")
target_link_libraries(hello ${CURSES_LIBRARIES})
