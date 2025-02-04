
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

/**
 * @brief Implementación de una estructura de datos Disjoint Set Union (DSU).
 * 
 * DSU es una estructura de datos que permite manejar particiones disjuntas y 
 * realizar uniones de conjuntos de manera eficiente. Se utiliza comúnmente en 
 * algoritmos de grafos como el algoritmo de Kruskal para encontrar árboles de 
 * expansión mínimos.
 */
class DSU {
    int* parent; ///< Arreglo que almacena el representante de cada conjunto.
    int* rank;   ///< Arreglo que almacena la altura del árbol de cada conjunto.

public:

    /**
     * @brief Constructor de la estructura DSU.
     * 
     * Inicializa la estructura con `n` elementos, donde cada nodo es su propio 
     * conjunto al inicio.
     * 
     * @param n Número de elementos en la estructura DSU.
     */
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1; ///< Cada nodo comienza siendo su propio conjunto.
            rank[i] = 1; ///< Altura inicial de cada conjunto es 1.
        }
    }

    /**
     * @brief Encuentra el representante (líder) del conjunto al que pertenece "i".
     * 
     * Utiliza la técnica de compresión de caminos para optimizar futuras búsquedas.
     * 
     * @param i Elemento a buscar en la estructura.
     * @return Representante del conjunto al que pertenece "i".
     */
    int Find(int i) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = Find(parent[i]); ///< Compresión de caminos.
    }

    /**
     * @brief Une dos conjuntos disjuntos en uno solo.
     * 
     * Aplica la técnica de unión por rango para mantener la estructura balanceada.
     * 
     * @param x Primer elemento.
     * @param y Segundo elemento.
     */
    void Unite(int x, int y) {
        int s1 = Find(x);
        int s2 = Find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2; ///< s2 se convierte en el líder.
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1; ///< s1 se convierte en el líder.
            } else {
                parent[s2] = s1;
                rank[s1] += 1; ///< Se incrementa el rango del nuevo líder.
            }
        }
    }

    /**
     * @brief Destructor de la estructura DSU.
     * 
     * Libera la memoria reservada dinámicamente para evitar fugas de memoria.
     */
    ~DSU() {
        delete[] parent;
        delete[] rank;
    }
};


/**
 * @brief Representa un grafo ponderado no dirigido.
 * 
 * Esta clase implementa un grafo utilizando una lista de aristas y proporciona
 * un método para encontrar el Árbol de Expansión Mínimo (MST) mediante el
 * algoritmo de Kruskal.
 */
class Graph {
    vector<vector<int>> edgeList; ///< Lista de aristas del grafo (peso, nodo1, nodo2).
    int V; ///< Número de vértices en el grafo.

public:
    /**
     * @brief Constructor de la clase Graph.
     * 
     * @param V Número de vértices en el grafo.
     */
    Graph(int V) { this->V = V; }

    /**
     * @brief Agrega una arista al grafo.
     * 
     * @param x Primer vértice de la arista.
     * @param y Segundo vértice de la arista.
     * @param w Peso de la arista.
     */
    void AddEdge(int x, int y, int w) {
        edgeList.push_back({w, x, y});
    }

    /**
     * @brief Calcula el Árbol de Expansión Mínimo (MST) usando el algoritmo de Kruskal.
     * 
     * Ordena las aristas por peso y usa la estructura DSU (Disjoint Set Union) para 
     * seleccionar las aristas que forman el MST, asegurando que no se formen ciclos.
     * 
     * @return El costo total del MST.
     */
    int KruskalsMST() {
        sort(edgeList.begin(), edgeList.end()); ///< Ordena las aristas por peso.

        DSU s(V);
        int ans = 0;
        int count = 0;

        for (auto edge : edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Si los nodos no están en el mismo conjunto, los unimos
            if (s.Find(x) != s.Find(y)) {
                s.Unite(x, y);
                ans += w;

                char u = 'A' + x;
                char v = 'A' + y;
                cout << "(" << u << ", " << v << ")" << endl;

                count++;
            }
            // Si ya tenemos V-1 aristas, terminamos
            if (count == V - 1) {
                break;
            }
        }
        return ans;
    }
};

