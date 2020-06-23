#ifndef GUARDA_DFS
#define GUARDA_DFS
#include <iostream>
#include <list>
using namespace std;

class Grafo{
    int V; //Numero de vertices
    list<int> *adj; //arreglo de listas de adyacencia
    bool *visited; //matriz de visitados.
public:
        Grafo(int V); //Constructor
        void addEdge(int v,int w); //GRAFO Dirigido de v -> w
        void DFS(int v); //DFS iniciando de v
        vector<int> ordenDFS(int v);
        vector<int> orden;

};

Grafo::Grafo(int V){
    this->V = V;
    adj = new list<int>[V];
    this->visited = new bool[this->V];
    for(int i=0;i<this->V;i++) this->visited[i] = false;
}

void Grafo::addEdge(int v,int w){
    adj[v].push_back(w); //agrega w a la posicion v
    adj[w].push_back(v); //si fuera no dirigido
}

void Grafo::DFS(int v){
    this->visited[v] = true; //marca el nodo actual como visitado e imprimelo
    orden.push_back(v);

    list<int>::iterator it;
    for(it = adj[v].begin(); it!=adj[v].end();++it){ //nodos adyacentes
        if(!this->visited[*it]){
            DFS(*it);
        }
    }
}

vector<int> Grafo::ordenDFS(int v){
    DFS(v);
    return orden;
}
#endif
/*
int main(){
    int V = 4;
    Grafo G(V);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(2,0);
    G.addEdge(2,3);
    G.addEdge(3,3);

    int src = 2;
    cout << "La DFS de G es (iniciando de el vertice 2): " << endl << endl;
    G.DFS(src);
    /**
    Si el grafo fuera disconexo:
        for(int i=0;i<V;i++){
            G.DFS(i);
        }
   
    return 0;
}
 */