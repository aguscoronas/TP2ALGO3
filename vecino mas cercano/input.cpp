#include "grafo.hpp"
#include <limits>

Grafo recibirInput(Grafo g){
    std::cin >> g.N;

    //creo la matriz de adjacencia
    std::vector<int> fila(g.N, std::numeric_limits<int>::max());
    for(int i = 0; i < g.N; i++)
        g.mA.push_back(fila);

    //lleno la matriz
    int m,i,j,c;
    std::cin >> m;
    for(m; m>0; m--){
        std::cin >> i;
        std::cin >> j;
        std::cin >> c;
        g.mA[i-1][j-1] = c;
        g.mA[j-1][i-1] = c;
    }
    
    for(int x = 0; x < g.N ; x++){
        for(int y = 0; y < g.N; y++){
            std::cout << g.mA[x][y] << " ";
        }
        std::cout << std::endl;
    }
    return g;
}

void output(std::vector<int> res) {
    //cantidad de vertices
    std::cout << res.size() - 1 << " ";
    //costo de la solucion optima
    std::cout << res[res.size() - 1] << std::endl;
    //secuencia de vertices optima
    for(int i = 0; i < res.size() - 1; i++)
        std::cout << res[i] << " ";
}