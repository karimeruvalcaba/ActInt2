
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

/* AUTORES
 * Carlos Ernesto Soto Alarcón A01747990
 * Sergio Alfonso Casillas Santoyo A01424863
 * Karime Itzel Ruvalcaba Pérez A01656188
 */
/**
 * @brief Convierte un índice numérico en una letra correspondiente.
 * @param index Índice a convertir.
 * @return Carácter en base a la conversión de índice a letra.
 *
 * @complejidad O(1) - Conversión directa de un índice a un carácter.
 */
char convert_to_letters(int index){
    return static_cast<char>('A' + index);
}

/**
 * @brief Formatea la salida del problema del viajero (TSP).
 * @param route Vector con la ruta obtenida del algoritmo.
 * @return Cadena de caracteres con la ruta formateada.
 *
 * @complejidad O(n) - Se recorre la ruta una vez para formatearla.
 */
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
                g.AddEdge(i, j, distances[i][j]);
            }
        }
    }

    cout << "Parte 1: Algoritmo de Kruskal: " << endl;
    g.KruskalsMST();

    cout << "Parte 2: Traveling Salesman Problem: " << endl;
    auto tsp_answer = TSP::Solve(V, distances);
    cout << format_tsp_output(tsp_answer) << endl;

    cout << "Parte 3: Edmonds-Karp algorithm: " << endl;
    int edmonds_karp_answer = EdmondsKarp::Solve(V, capacities, 0, V -1);
    cout << edmonds_karp_answer << endl;

    cout << "Parte 4: Busqueda Lineal: " << endl;
    auto busqueda_lineal_answer = LinealSearch::Find(centrals, new_contract);
    cout << "(" << busqueda_lineal_answer.first << ", " << busqueda_lineal_answer.second << ")" << endl;

    return 0;
}
