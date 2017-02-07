cmake_minimum_required (VERSION 2.6)
project (p3)
add_executable(ej1 ej1.c)
add_executable(ej2 ej2.c)
add_executable(ej3 ej3.c)
add_executable(p1 p1_proc.c)
add_executable(p2 p2_proc.c)
add_executable(ej4 ej4.c)
add_executable(ej5a ej5_a.c)
add_executable(ej5b ej5_b.c)
add_executable(ej6p ej6_p.c)
add_executable(ej6q ej6_q.c)
add_executable(ej7p ej7_p.c)
add_executable(ej7q ej7_q.c)
set(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR}/out
)