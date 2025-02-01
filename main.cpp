#include <iostream>
#include "kruskal.h"
using namespace std;

int main(){
    int V;
    cin >> V;

    Graph g(V);

    for (int i=0; i < V; ++i){
        for (int j=0; j < V; ++j){

            int weight;
            cin >> weight;

            if (j > i && weight != 0){
                g.addEdge(i, j, weight);
            }
        }
    }

    g.kruskals_mst();
    return 0;
}