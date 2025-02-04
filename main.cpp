#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <limits>
#include "kruskal.h"
#include "tsp.h"
#include "edmonds_karp.h"
#include "lineal_search.h"
using namespace std;

char convert_to_letters(int index){
    return static_cast<char>('A' + index);
}

string format_tsp_output(const vector<int>& route){
    string result;
    for (int node : route){
        result += convert_to_letters(node);
        result += " ";
    }
    result += convert_to_letters(route[0]);
    return result;
}

int main(){
    int V;
    cin >> V;

    // Read distances
    vector<vector<int>> distances(V, vector<int>(V));
    for (int i = 0; i < V; ++i){
        for (int j = 0; j < V; j++){
            cin >> distances[i][j];
        }
    }

    // Read capacities
     vector<vector<int>> capacities(V, vector<int>(V));
    for (int i = 0; i < V; ++i){
        for (int j = 0; j < V; j++){
            cin >> capacities[i][j];
        }
    }   

    // Read centrals
    vector<pair<int, int>> centrals;
    for (int i = 0; i < V; ++i){
        int x, y;
        char ch;
        cin >> ch; // Read '('
        cin >> x;
        cin >> ch; // Read ','
        cin >> y;
        cin >> ch; // Read ')'
        centrals.emplace_back(x, y);
    }

    // Read new contract
    int x, y;
    char ch;
    cin >> ch; // Read '('
    cin >> x;
    cin >> ch; // Read ','
    cin >> y;
    cin >> ch; // Read ')'
    pair<int, int> new_contract = {x, y};
        
    // Graph for Kruskal
    Graph g(V);
    for (int i = 0; i < V; ++i){
        for (int j = i + 1; j < V; ++j){
            if (distances[i][j] != 0){
                g.addEdge(i, j, distances[i][j]);
            }
        }
    }

    cout << "Parte 1: Algoritmo de Kruskal: " << endl;
    g.kruskals_mst();

    cout << "Parte 2: Traveling Salesman Problem: " << endl;
    auto tsp_answer = TSP::solve(V, distances);
    cout << format_tsp_output(tsp_answer) << endl;

    cout << "Parte 3: Edmonds-Karp algorithm: " << endl;
    int edmonds_karp_answer = EdmondsKarp::solve(V, capacities, 0, V -1);
    cout << edmonds_karp_answer << endl;

    cout << "Parte 4: Busqueda Lineal: " << endl;
    auto busqueda_lineal_answer = lineal_search::find(centrals, new_contract);
    cout << "(" << busqueda_lineal_answer.first << ", " << busqueda_lineal_answer.second << ")" << endl;

    return 0;
}