cmake_minimum_required(VERSION 3.17.3)
project(ProgettoLab)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES Notes.cpp Notes.h Collezione.cpp Collezione.h Observer.h Subject.h Displayer.cpp Displayer.h)
add_executable(ProgettoLab main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ProgettoLab core)
