// g++ solucionACompletar.cpp -O2 -o solucion

#include <iostream>
#include <algorithm>
#include <vector>
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

struct arista {
	int inicio;
	int fin;
	int costo;
	
	bool operator<(const arista a) const{
		if(costo != a.costo)
			return costo < a.costo;
		if(inicio != a.inicio)
			return inicio < a.inicio;
		return fin < a.fin;
	}
};

int main(){
	int V, E;
	cin >> V >> E;
	init(V);
	vector<arista> aristas;
	vector<arista> res;
	for(int i = 0; i < E; i++){
		arista a;
		cin >> a.inicio >> a.fin >> a.costo;
		aristas.push_back(a);
	}
	
	sort(aristas.begin(), aristas.end()); // ordeno las aristas por peso de menor a mayor

	for (int i = 0; i < E; i++){
		arista a = aristas[i];
		if(find(a.inicio) != find(a.fin)){
			uni(a.inicio, a.fin);
			res.push_back(a);
		}
	}
	
	// formato de salida para python...
	cout << V << " " << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
		cout << res[i].inicio << " " << res[i].fin << " " << res[i].costo << endl;
	}
}
