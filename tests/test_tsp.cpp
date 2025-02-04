#include <gtest/gtest.h>
#include "../tsp.h"

// TEST 1: Grafo pequeño
TEST(test_tsp, test_1_tsp)
{
    vector<vector<int>> distancias = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    vector<int> expected_route = {0, 1, 3, 2}; 
    ASSERT_EQ(TSP::solve(4, distancias), expected_route);
}

// TEST 2: Grafo mediano 
TEST(test_tsp, test_2_tsp)
{
    vector<vector<int>> distancias = {
        {0, 29, 20, 21},
        {29, 0, 15, 17},
        {20, 15, 0, 28},
        {21, 17, 28, 0}
    };
    vector<int> expected_route = {0, 2, 1, 3}; // One of the possible optimal routes
    ASSERT_EQ(TSP::solve(4, distancias), expected_route);
}

// TEST 3: Grafo grande
TEST(test_tsp, test_3_tsp)
{
    vector<vector<int>> distancias = {
        {0, 10, 8, 9, 7},
        {10, 0, 10, 5, 6},
        {8, 10, 0, 8, 9},
        {9, 5, 8, 0, 6},
        {7, 6, 9, 6, 0}
    };
    vector<int> expected_route = {0, 4, 1, 3, 2}; 
    ASSERT_EQ(TSP::solve(5, distancias).size(), expected_route.size());
}

// TEST 4: Solo una ruta valida
TEST(test_tsp, test_4_tsp)
{
    vector<vector<int>> distancias = {
        {0, 1},
        {1, 0}
    };
    vector<int> expected_route = {0, 1};
    ASSERT_EQ(TSP::solve(2, distancias), expected_route);
}
