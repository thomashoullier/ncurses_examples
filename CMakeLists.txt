cmake_minimum_required(VERSION 3.20)
project(ncurses_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src/")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
find_library(PANEL_LIBRARY panel)
find_library(MENU_LIBRARY menu)

add_executable(hello "${SRC_DIR}/hello.cpp")
target_link_libraries(hello ${CURSES_LIBRARIES})

add_executable(example_2 "${SRC_DIR}/example_2.cpp")
target_link_libraries(example_2 ${CURSES_LIBRARIES})

add_executable(example_3 "${SRC_DIR}/example_3.cpp")
target_link_libraries(example_3 ${CURSES_LIBRARIES})

add_executable(example_4 "${SRC_DIR}/example_4.cpp")
target_link_libraries(example_4 ${CURSES_LIBRARIES})

add_executable(example_5 "${SRC_DIR}/example_5.cpp")
target_link_libraries(example_5 ${CURSES_LIBRARIES})

add_executable(example_6 "${SRC_DIR}/example_6.cpp")
target_link_libraries(example_6 ${CURSES_LIBRARIES})

add_executable(example_7 "${SRC_DIR}/example_7.cpp")
target_link_libraries(example_7 ${CURSES_LIBRARIES})

add_executable(example_8 "${SRC_DIR}/example_8.cpp")
target_link_libraries(example_8 ${CURSES_LIBRARIES})

add_executable(example_9 "${SRC_DIR}/example_9.cpp")
target_link_libraries(example_9 ${CURSES_LIBRARIES})

add_executable(example_10 "${SRC_DIR}/example_10.cpp")
target_link_libraries(example_10 ${CURSES_LIBRARIES})

add_executable(example_11 "${SRC_DIR}/example_11.cpp")
target_link_libraries(example_11 ${CURSES_LIBRARIES})

add_executable(example_12 "${SRC_DIR}/example_12.cpp")
target_link_libraries(example_12 ${CURSES_LIBRARIES})

add_executable(example_13 "${SRC_DIR}/example_13.cpp")
target_link_libraries(example_13 ${CURSES_LIBRARIES})

add_executable(example_14 "${SRC_DIR}/example_14.cpp")
target_link_libraries(example_14 ${CURSES_LIBRARIES} ${PANEL_LIBRARY})

add_executable(example_15 "${SRC_DIR}/example_15.cpp")
target_link_libraries(example_15 ${CURSES_LIBRARIES} ${PANEL_LIBRARY})

add_executable(example_16 "${SRC_DIR}/example_16.cpp")
target_link_libraries(example_16 ${CURSES_LIBRARIES} ${PANEL_LIBRARY})

add_executable(example_17 "${SRC_DIR}/example_17.cpp")
target_link_libraries(example_17 ${CURSES_LIBRARIES} ${PANEL_LIBRARY})

add_executable(example_18 "${SRC_DIR}/example_18.cpp")
target_link_libraries(example_18 ${CURSES_LIBRARIES} ${MENU_LIBRARY})

add_executable(example_19 "${SRC_DIR}/example_19.cpp")
target_link_libraries(example_19 ${CURSES_LIBRARIES} ${MENU_LIBRARY})
