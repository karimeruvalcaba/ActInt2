#ifndef LINEAL_SEARCH_H
#define LINEAL_SEARCH_H

#include <vector>
#include <utility>
#include <cmath>
#include <limits>
using namespace std;

class lineal_search{
    public:

    static pair<int, int> find(const vector<pair<int, int>>& centrals, const pair<int, int>& new_contract){
        double min_distance = numeric_limits<double>max();
        pair<int, int> closest_central;

        for (const auto& central: centrals){
            double distance = hypot(central.first - new_contract.first, central.second - new_contract.second);
            if (distance < min_distance){
                min_distance = distance;
                closest_central = central;
            }
        }
        return closest_central;
    }
};

# endif