#include <gtest/gtest.h>
#include "../edmonds_karp.h" 


TEST(test_edmonds_karp, test_1_edmonds_karp)
{
    edmonds_karp edmonds_karp_test_1;
    vector<vector<int>> capacity = {{0, 3, 3, 0, 0, 0},
                                    {0, 0, 2, 3, 0, 0},
                                    {0, 0, 0, 0, 2, 0},
                                    {0, 0, 0, 0, 4, 2},
                                    {0, 0, 0, 0, 0, 2},
                                    {0, 0, 0, 0, 0, 3}};
    
    int V = capacity.size()
    ASSERT_EQ(edmonds_karp::solve(V, capacity, 0, V - 1), 5);
}

