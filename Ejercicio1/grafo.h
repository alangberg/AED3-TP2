#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

class Grafo {
public:
	struct Nodo {
		Nodo(int i, vector<pair<int,int> > l = vector<pair<int, int> > ()) : id(i) {};
		Nodo() :  id(-1), vecinos(vector<pair<int, int> > ()) {};
		
		int id;
		vector<pair<int, int> > vecinos; // si pair.first ==1 los nodos son vecinos, si es 2 hay una pared.
	};

	~Grafo();
	Grafo();
	// Grafo(int cantnodos);

	Nodo* nuevoNodo();
	// Nodo* vecino(int id, int i);

	// void leer(int filas, int columnas);
	int caminoMinimo(int origen, int destino, int P);
	void imprimir();
	
	int _cantnodos;
	vector<Nodo*> _nodos;
};

Grafo::Grafo() {
	this->_cantnodos = 0;
	this->_nodos = vector<Nodo*>();
}

Grafo::Nodo* Grafo::nuevoNodo() {
	Nodo* nodo = new Nodo;
	this->_nodos.push_back(nodo);
	this->_cantnodos++;
	return nodo;
}

Grafo::~Grafo() {
	// delete[] &(this->_nodos);
	for (int i = 0; i < this->_nodos.size(); ++i) {
		delete this->_nodos[i];
	}
}

void Grafo::imprimir() {
	cout << '{' << endl;
	for (unsigned int i = 0; i < this->_nodos.size(); i++) {
		cout << this->_nodos[i]->id << " [ ";
		for (unsigned int j = 0; j < this->_nodos[i]->vecinos.size(); j++) {
			cout << "(" << this->_nodos[i]->vecinos[j].first << ", " << this->_nodos[i]->vecinos[j].second << ") ";
		}
		cout << "] " << endl;
	}
	cout << "} " << endl;

}

int Grafo::caminoMinimo(int origen, int destino, int P){
	


	vector<int> distancias (this->_cantnodos, -1);
	distancias[origen] = 0;

	queue<pair<int, int> > q;
	q.push(pair<int, int>(origen, P));
	
	int j=0;
	while(!q.empty()){
		pair<int, int> actual = q.front();
		q.pop();

		int pAux = actual.second;
		int nodoActual = actual.first;

		for (int i = 0; i < _nodos[nodoActual]->vecinos.size(); i++){
			if(distancias[_nodos[nodoActual]->vecinos[i].second] == -1 && ((!(_nodos[nodoActual]->vecinos[i].first == 2)) || pAux > 0 )) {
				if(_nodos[nodoActual]->vecinos[i].first == 2) pAux--;
				
				distancias[_nodos[nodoActual]->vecinos[i].second] = distancias[nodoActual] + _nodos[nodoActual]->vecinos[i].first;

				q.push(pair<int, int> (_nodos[nodoActual]->vecinos[i].second, pAux));
			}
		}
		j++;
	}

	return distancias[destino];


}

// Grafo::Nodo* Grafo::vecino(int id, int i){
// 	int s = _nodos[id]->vecinos[i].second;
// 	return _nodos[s];
// }
