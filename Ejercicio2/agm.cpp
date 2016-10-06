#include <iostream>
#include <algorithm>
#include <vector>
#include "grafo.h"

using namespace std;

vector<int> altura;
vector<int> padre;

void init(int n) {
	altura.reserve(n);
	padre.reserve(n);
	for(int i = 0; i < n; i++){
		padre[i] = i;
		altura[i] = 1;
	}
}

int find(int x) {
	if(padre[x] != x){
		padre[x] = find(padre[x]);
	}
	return padre[x];
}

void uni(int x, int y) {
	// union es una palabra reservada en C++, por eso usamos "uni"
	x = find(x);
	y = find(y);
	if(altura[x] < altura[y]){
		padre[x] = y;
	} else {
		padre[y] = x;
		if(altura[x] == altura[y]){
			altura[y]++;
		}
	}
}

void kruskal(Grafo& g){
	int V = g.cantidadNodos();
	int E = g.cantidadAristas();
	init(V);
	vector<Grafo::Arista> res;
	vector<Grafo::Arista> aristas;

	for(int i = 0; i < E; i++)
		aristas.push_back(g.iesimaArista(i)); // copiamos las aristas
	
	sort(aristas.begin(), aristas.end()); // ordenamos las aristas por peso de menor a mayor

	for(int i = 0; i < aristas.size(); i++){
		Grafo::Arista a = aristas[i];
		if(find(a.inicio) != find(a.fin)){
			uni(a.inicio, a.fin);
			res.push_back(a);
		}
	}

	g.eliminarAristas(); // O(E)

	for(int i = 0; i < res.size(); i++)
		g.agregarArista(res[i].inicio, res[i].fin, res[i].peso);
}