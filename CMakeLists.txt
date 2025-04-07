cmake_minimum_required(VERSION 3.10.0)
project(prog1 VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(test)

set(SOURCE_FILES DateTime.cpp Countdown.cpp UI.cpp)


add_library(core ${SOURCE_FILES})


add_executable(prog1 main.cpp)
target_link_libraries(prog1 core)



find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(prog1 ${CURSES_LIBRARIES})
