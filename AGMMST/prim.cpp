
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include "DFS.hpp"
using namespace std;

//vecino, costo
using neigh = pair<int, int>;
using graph = vector<vector<neigh>>;

using edge = tuple<int,int,int>;

int& cost(edge& e) {return get<0>(e);}
int& first(edge& e) {return get<1>(e);}
int& second(edge& e) {return get<2>(e);}


const int none = -1;

int costo(neigh x) {return x.second;}
int vecino(neigh x) {return x.first;}

int main() {
  //transformacion de aristas a adyacencias
  int n, m; cin >> n >> m;
  int r = 0;
  graph G(n);
  for(int i = 0; i < m; ++i) {
    int v, w, c; cin >> v >> w >> c;
    G[v-1].push_back({w - 1,c});
    G[w-1].push_back({v - 1,c});
  }
  
  //algoritmo de prim
  vector<int> T(n, none); T[r] = r;
  priority_queue<edge> S;
  for(auto x : G[r]) S.push({-costo(x), r, vecino(x)});
  //el for se puede ejecutar hasta que S = vacio
  for(int i = 0; i < n-1;) {
    int c, v, w;
    tie(c,v,w) = S.top();
    S.pop();
    if(T[w] == none) {
      T[w] = v; ++i;
      //el if que sigue es opcional
      for(auto x : G[w]) if(T[vecino(x)] == none)
        S.push({-costo(x), w, vecino(x)});
    }
  }
  
  //duplico aristas y hago dfs
  Grafo gMST(n);
  for(int i = 0; i < n; i++)
    if(T[i] != i )
      gMST.addEdge(i, T[i]);
  
  //consigo el costo total
  vector<int> DFS = gMST.ordenDFS(0);
  int CostoTotal = 0;
  for(int i = 0; i < n; i++)
      for(neigh g : G[DFS[i]]) 
        if(vecino(g) == DFS[(i+1)%n])
          CostoTotal += costo(g);
    
  //output
  cout << n << " " << CostoTotal << endl;
  for(int i : DFS)
    cout << i + 1 << " ";

}

