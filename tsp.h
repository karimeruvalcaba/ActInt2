
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
 
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