#ifndef TSP_H
#define TSP_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

class TSP{
public:
    static vector<int> solve(int n, vector<vector<int>>& distancias){
        vector<int> nodes(n - 1);
        iota(nodes.begin(), nodes.end(), 1);

        vector<int> best_route;
        int min_cost = INT_MAX;

        do {
            vector<int> route = {0};
            route.insert(route.end(), nodes.begin(), nodes.end());
            int cost = 0;
            for (int i = 0; i < n - 1; ++i){
                cost += distancias[route[i]][route[i +1]];
            }
            cost += distancias[route.back()][route[0]];
            if (cost < min_cost){
                min_cost = cost;
                best_route = route;
            }
        } while (next_permutation(nodes.begin(), nodes.end()));

        return best_route;
    }

};

#endif