#include "grafo.hpp"
#include <algorithm>
#include <limits>

std::vector<int> vecinoMasCercano(Grafo g){
    std::vector<int> H;
    int costoTotal = 0;
    //el 1er vertice del ciclo es 1 x enunciado
    int v = 1;
    H.push_back(v);
    std::vector<int> copia(g.mA[v-1]);
    while(H.size() < g.N){
        //marco v como visitado
        for(int i = 0; i < g.N; i++){
            g.mA[i][v-1] = std::numeric_limits<int>::max();
        }
        //encuentro el vecino mas cercano
        std::vector<int>::iterator result = std::min_element(g.mA[v-1].begin(), g.mA[v-1].end());
        //actualizo costo
        costoTotal += *result;
        //actualizo v
        v = std::distance(g.mA[v-1].begin(), result) + 1;
        //agrego v al camino
        H.push_back(v);        
    }
    //agrego el costo de volver al vertice inicial desde el ultimo vertice
    costoTotal += copia[v-1];
    //OJO!! 
    //agrego costo total al final del vector resultado
    H.push_back(costoTotal);
    return H;
}