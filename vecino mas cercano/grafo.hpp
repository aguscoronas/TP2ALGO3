#ifndef HEADERGRAFO
#define HEADERGRAFO
#include <vector>
#include <iostream>

class Grafo{
    public:
    int N;
    std::vector<std::vector<int>> mA;
};

Grafo recibirInput(Grafo g);
std::vector<int> vecinoMasCercano(Grafo g);
void output(std::vector<int> resultado);
#endif