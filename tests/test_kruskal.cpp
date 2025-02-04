#include <gtest/gtest.h>
#include "../kruskal.h" 

TEST(test_kruskal, test_1_kruskal)
{
    Graph g(4); 

    g.AddEdge(0, 1, 10);
    g.AddEdge(1, 3, 15);
    g.AddEdge(2, 3, 4);
    g.AddEdge(2, 0, 6);
    g.AddEdge(0, 3, 5);

    ASSERT_EQ(g.KruskalsMST(), 19); 
}

TEST(test_kruskal, test_2_kruskal)
{
    Graph g(5);

    g.AddEdge(0, 1, 2);
    g.AddEdge(1, 2, 3);
    g.AddEdge(2, 3, 1);
    g.AddEdge(3, 4, 4);
    g.AddEdge(4, 0, 5);
    g.AddEdge(1, 4, 6);
    g.AddEdge(0, 2, 7);

    ASSERT_EQ(g.KruskalsMST(), 10); 
}

TEST(test_kruskal, test_3_kruskal)
{
    Graph g(6);

    g.AddEdge(0, 1, 1);
    g.AddEdge(1, 2, 2);
    g.AddEdge(2, 3, 3);
    g.AddEdge(3, 4, 4);
    g.AddEdge(4, 5, 5);
    g.AddEdge(5, 0, 6);
    g.AddEdge(1, 3, 2);
    g.AddEdge(2, 4, 3);

    ASSERT_EQ(g.KruskalsMST(), 13); 
}

TEST(test_kruskal, test_4_kruskal)
{
    Graph g(7);

    g.AddEdge(0, 1, 4);
    g.AddEdge(0, 2, 3);
    g.AddEdge(1, 2, 1);
    g.AddEdge(1, 3, 2);
    g.AddEdge(2, 3, 4);
    g.AddEdge(3, 4, 2);
    g.AddEdge(4, 5, 6);
    g.AddEdge(5, 6, 7);
    g.AddEdge(4, 6, 5);

    ASSERT_EQ(g.KruskalsMST(), 19); 
}
