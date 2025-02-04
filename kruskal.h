
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
 
#include <bits/stdc++.h>
using namespace std;

class DSU{

    int* parent;
    int* rank;

public:

    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        
        for (int i= 0; i < n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i){

        if (parent[i] == -1){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y){

        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2){

            if (rank[s1] < rank[s2]){
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]){
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] +=1;
            }
        }
    }
};

class Graph{

    vector<vector<int>> edgeList;
    int V;

    public:
    Graph(int V) {this ->V = V;}

    void addEdge(int x, int y, int w){
        edgeList.push_back({ w, x, y});
    }

    int kruskals_mst(){

        sort(edgeList.begin(), edgeList.end());

        DSU s(V);
        int ans = 0;
        int count = 0; 
        //cout << "Parte 1: Algoritmo de Kruskal: " << endl;
        for (auto edge : edgeList){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y)){

                s.unite(x, y);
                ans += w;

                char u = 'A' + x;
                char v = 'A' + y;

                cout << "(" << u << ", " << v << ")" << endl;

                count++;
            }
            if (count == V - 1){
                break;
            }
        }
        //cout << "Minimum Cost Spanning Tree: " << ans;
        return ans;
    }
};