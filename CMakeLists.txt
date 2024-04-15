cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled "laboratornaya/tests/tests for vector.c"
        libs/algorithms/array/array.c
        libs/algorithms/array/array.h
        libs/algorithms/algorithm.c
        libs/algorithms/algorithm.h
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        laboratornaya/laboratornaya_16/laboratornaya_16.c
        main.c
        "laboratornaya/tests/tests for laboratornaya_16.c"
        "laboratornaya/tests/tests for matrix.c"
        "laboratornaya/tests/tests for laboratornaya_16.h"
        "laboratornaya/tests/tests for matrix.h"
        "laboratornaya/tests/tests for vector.h"
        "laboratornaya/tests/tests for string.c"
        "laboratornaya/tests/tests for string.h"
)

add_subdirectory(libs)
target_link_libraries(untitled algorithms)
target_link_libraries(untitled data_structures)

