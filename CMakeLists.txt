cmake_minimum_required (VERSION 2.6)
project (p3)
add_executable(ej1 ej1.c)
add_executable(ej2 ej2.c)
add_executable(ej3 ej3.c)
add_executable(p1 p1_proc.c)
add_executable(p2 p2_proc.c)
set(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR}/out
)