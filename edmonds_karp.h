
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
 
#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class edmonds_karp{
public:
    static int solve(int n, const vector<vector<int>>& capacity, int source, int sink){

        vector<vector<int>> flow(n, vector<int>(n, 0));
        vector<int> parent(n, -1);
        int max_value_flow = 0;

        auto bfs = [&](){

            fill(parent.begin(), parent.end(), -1);
            queue<int> q;
            q.push(source);
            parent[source] = -2;
            while (!q.empty()){
                int u = q.front();
                q.pop();
                for (int v = 0; v < n; ++v){
                    if (parent[v] == -1 && capacity[u][v] > flow[u][v]){
                        parent[v] = u;
                        q.push(v);
                        if (v == sink){
                            return true;
                        }
                    }
                }
            }
            return false;
        };

        while (bfs()){

            int flow_path = INT_MAX;
            for (int v = sink; v!= source; v = parent[v]){
                int u = parent[v];
                flow_path = min(flow_path, capacity[u][v] - flow[u][v]);
            }
            for (int v = sink; v!= source; v = parent[v]){
                int u = parent[v];
                flow[u][v] += flow_path;
                flow[v][u] -= flow_path;
            }
            max_value_flow += flow_path;
        }
        return max_value_flow;
    }
};

#endif