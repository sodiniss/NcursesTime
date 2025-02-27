cmake_minimum_required(VERSION 3.10.0)
project(prog1 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(prog1 main.cpp DateTime.cpp Countdown.cpp UI.cpp)

include(CTest)
enable_testing()

# Trova la libreria ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
# Linka ncurses
target_link_libraries(prog1 ${CURSES_LIBRARIES})