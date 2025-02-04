#include <gtest/gtest.h>
#include "../edmonds_karp.h" 

// TEST 1: Grafo simple 
TEST(test_edmonds_karp, test_1_edmonds_karp)
{
    edmonds_karp edmonds_karp_test_1;
    vector<vector<int>> capacity = {{0, 3, 3, 0, 0, 0},
                                    {0, 0, 2, 3, 0, 0},
                                    {0, 0, 0, 0, 2, 0},
                                    {0, 0, 0, 0, 4, 2},
                                    {0, 0, 0, 0, 0, 2},
                                    {0, 0, 0, 0, 0, 3}};
    
    int V = capacity.size();
    ASSERT_EQ(EdmondsKarp::solve(V, capacity, 0, V - 1), 4);
}

// TEST 2: Grafo simple 2
TEST(test_edmonds_karp, test_2_edmonds_karp)
{
    vector<vector<int>> capacity = {{0, 5, 0, 0},
                                    {0, 0, 4, 0},
                                    {0, 0, 0, 6},
                                    {0, 0, 0, 0}}; 

    int V = capacity.size(); 

    ASSERT_EQ(EdmondsKarp::solve(V, capacity, 0, V - 1), 4); 
}

// TEST 3: Grafo desconectado (Sin destino)
TEST(test_edmonds_karp, test_3_edmonds_karp)
{
    vector<vector<int>> capacity = {{0, 5, 0, 0},
                                    {0, 0, 4, 0},
                                    {0, 0, 0, 0},  
                                    {0, 0, 0, 0}};

    int V = capacity.size(); 

    ASSERT_EQ(EdmondsKarp::solve(V, capacity, 0, V - 1), 0); 
}

// TEST 4: Red compleja, con varios caminos
TEST(test_edmonds_karp, test_4_edmonds_karp)
{
    vector<vector<int>> capacity = {{0, 10, 10, 0, 0, 0},
                                    {0, 0, 2, 4, 8, 0},
                                    {0, 0, 0, 0, 9, 0},
                                    {0, 0, 0, 0, 0, 10},
                                    {0, 0, 0, 6, 0, 10},
                                    {0, 0, 0, 0, 0, 0}};

    int V = capacity.size(); 

    ASSERT_EQ(EdmondsKarp::solve(V, capacity, 0, V - 1), 19); 
}
