#include <gtest/gtest.h>
#include "../kruskal.h" 

TEST(test_kruskal, test_1_kruskal)
{
    Graph g(4); 

    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    ASSERT_EQ(g.kruskals_mst(), 19); 
}

TEST(test_kruskal, test_2_kruskal)
{
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 0, 5);
    g.addEdge(1, 4, 6);
    g.addEdge(0, 2, 7);

    ASSERT_EQ(g.kruskals_mst(), 10); 
}

TEST(test_kruskal, test_3_kruskal)
{
    Graph g(6);

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 5);
    g.addEdge(5, 0, 6);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 3);

    ASSERT_EQ(g.kruskals_mst(), 13); 
}

TEST(test_kruskal, test_4_kruskal)
{
    Graph g(7);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);
    g.addEdge(5, 6, 7);
    g.addEdge(4, 6, 5);

    ASSERT_EQ(g.kruskals_mst(), 19); 
}
