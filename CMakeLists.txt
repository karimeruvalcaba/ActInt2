cmake_minimum_required(VERSION 3.30)
project(unit_test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        main.cpp
        test_edmonds_karp.h
        test_kruskal.h
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

    # Test Suite 1: Edmonds-Karp
    add_executable(test_edmonds_karp tests/test_edmonds_karp.cpp)
    target_link_libraries(test_edmonds_karp PRIVATE gtest gtest_main)
    add_test(NAME TestEdmondsKarp COMMAND test_edmonds_karp)

    # Test Suite 2: Kruskal
    add_executable(test_kruskal tests/test_kruskal.cpp)
    target_link_libraries(test_kruskal PRIVATE gtest gtest_main)
    add_test(NAME TestKruskal COMMAND test_kruskal)
endif()

