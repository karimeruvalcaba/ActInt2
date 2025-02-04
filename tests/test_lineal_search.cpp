#include <gtest/gtest.h>
#include "../lineal_search.h"

TEST(test_lineal_search, test_1_lineal_search)
{
    vector<pair<int, int>> centrals = {{0, 0}, {5, 5}, {10, 10}};
    pair<int, int> new_contract = {3, 3};
    ASSERT_EQ(lineal_search::find(centrals, new_contract), make_pair(5, 5));
}

TEST(test_lineal_search, test_2_lineal_search)
{
    vector<pair<int, int>> centrals = {{1, 2}, {3, 4}, {6, 8}};
    pair<int, int> new_contract = {4, 5};
    ASSERT_EQ(lineal_search::find(centrals, new_contract), make_pair(3, 4));
}

TEST(test_lineal_search, test_3_lineal_search)
{
    vector<pair<int, int>> centrals = {{-5, -5}, {0, 0}, {5, 5}};
    pair<int, int> new_contract = {-3, -3};
    ASSERT_EQ(lineal_search::find(centrals, new_contract), make_pair(-5, -5));
}

TEST(test_lineal_search, test_4_lineal_search)
{
    vector<pair<int, int>> centrals = {{100, 100}, {200, 200}, {300, 300}};
    pair<int, int> new_contract = {250, 250};
    ASSERT_EQ(lineal_search::find(centrals, new_contract), make_pair(200, 200));
}