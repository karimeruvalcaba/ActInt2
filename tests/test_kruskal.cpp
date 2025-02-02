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
