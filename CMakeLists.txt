option(ENABLE_COVERAGE "Enable coverage reporting" ON)
cmake_minimum_required(VERSION 3.30)
project(unit_test)

set(CMAKE_CXX_STANDARD 17)

if (ENABLE_COVERAGE)
    message(STATUS "Enabling coverage flags for GCC/Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

set(SOURCES
        main.cpp
        edmonds_karp.h
        kruskal.h
        lineal_search.h
        tsp.h
)

add_executable(unit_test main.cpp)

# Opciones
option(ENABLE_TESTING "Enable a Unit Testing build." ON)

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Si se habilitan las pruebas, agrega GoogleTest y las pruebas unitarias
if(ENABLE_TESTING)
    enable_testing()

    function(add_test_executable name source)
        add_executable(${name} ${source})
        target_link_libraries(${name} PRIVATE gtest gtest_main)
        if (ENABLE_COVERAGE)
            target_link_libraries(${name} PRIVATE gcov)
            target_compile_options(${name} PRIVATE --coverage -fprofile-arcs -ftest-coverage)
            target_link_options(${name} PRIVATE --coverage)
        endif()
        add_test(NAME ${name} COMMAND ${name})
    endfunction()

    add_test_executable(test_edmonds_karp tests/test_edmonds_karp.cpp)
    add_test_executable(test_kruskal tests/test_kruskal.cpp)
    add_test_executable(test_lineal_search tests/test_lineal_search.cpp)
    add_test_executable(test_tsp tests/test_tsp.cpp)

endif()
