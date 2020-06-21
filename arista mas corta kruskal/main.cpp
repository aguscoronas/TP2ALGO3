
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "disjoint-set.h"

using namespace std;

using edge = tuple<int,int,int>;

int& cost(edge& e) {return get<0>(e);}
int& first(edge& e) {return get<1>(e);}
int& second(edge& e) {return get<2>(e);}

int main() {
  //lectura de la lista de aristas
  int n, m; cin >> n >> m;
  vector<edge> E(m);
  vector<edge> cicloH;
  for(int i = 0; i < m; ++i) 
    cin >> first(E[i]) >> second(E[i]) >> cost(E[i]);
  
  //sort inicial
  sort(E.begin(), E.end());
  //saturacion de los vertices
  vector<int> saturacion(n,0);
  float costoTotal = 0;
  //algoritmo de Kruskal
  DisjointSet ds(n);
  for(int i = 0, j = 0; i < n-1; ++i) {
    while(saturacion[first(E[j]) - 1] == 2 ||
    saturacion[second(E[j]) - 1] == 2 ||
    (ds.find(first(E[j]) - 1) == ds.find(second(E[j]) - 1))){
      ++j;
    }
    saturacion[first(E[j])-1]++;
    saturacion[second(E[j])-1]++;
    costoTotal += cost(E[j]);
    cicloH.push_back(E[j]);
    ds.unite(first(E[j]) - 1,second(E[j]) - 1);
  }

  //busco la arista que me falta para completar el ciclo
  int sueltos [2];
  for(int i = 0, j = 0; i < n; i++){
    if(saturacion[i] == 1)
      sueltos[j++] = i + 1;
  }
  //la agrego al ciclo
  for(edge e : E){
    if((first(e) == sueltos[0] && second(e) == sueltos[1]) ||
      (first(e) == sueltos[1] && second(e) == sueltos[0])){
      costoTotal += cost(e);
      cicloH.push_back(e);
      }
  }

  // output
  cout << n << " " << costoTotal << endl;

  int v = 1, predV = -1;
  for(int i = 0; i < n - 1; i++){
    cout << v << " ";

    for(edge e : cicloH){
      if(first(e) == v && second(e) != predV){
        predV = v;
        v = second(e);
        break;
      }
      else if(first(e) != predV && second(e) == v ){
        predV = v;
        v = first(e);
        break;
      }
    }
  }
  cout << v << endl;

}
