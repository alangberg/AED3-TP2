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
		Nodo(int i, vector<int> l = vector<int> ()) : id(i) {};
		Nodo() :  id(-1), vecinos(vector<int> ()), pared(false) {};
		
		bool pared;
		int id;
		vector<int> vecinos;
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
	vector<vector<Nodo*> > _nodos;
};

Grafo::Grafo() {
	this->_cantnodos = 0;
	this->_nodos = vector<vector<Nodo*> >();
}

Grafo::Nodo* Grafo::nuevoNodo() {
	Nodo* nodo = new Nodo;
	for (int i = 0; i < _nodos.size(); ++i){
		_nodos[i].push_back(nodo);
	}
	this->_cantnodos++;
	return nodo;
}

Grafo::~Grafo() {
	// delete[] &(this->_nodos);
	for (int i = 0; i < this->_nodos.size(); ++i) {
		for (int j = 0; i < this->_nodos[i].size(); ++j){
			/* code */
		delete this->_nodos[i][j];
		}
	}
}

void Grafo::imprimir() {
	cout << '{' << endl;
	for (unsigned int i = 0; i < this->_nodos.size(); i++) {
		cout << ' ' << this->_nodos[i]->id << " [ ";
		for (unsigned int j = 0; j < this->_nodos[i]->vecinos.size(); j++) {
			cout << this->_nodos[i]->vecinos[j] << ' ';
		}
		cout << "] " << this->_nodos[i]->pared << endl;
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

		int nodoActual = actual.first;
		int pAux;

		for (int i = 0; i < _nodos[nodoActual]->vecinos.size(); i++){
			pAux = actual.second;
			int vecino = _nodos[nodoActual]->vecinos[i];

			if(distancias[vecino] == -1 && (!(_nodos[vecino]->pared) || pAux > 0 )) {
				if(_nodos[vecino]->pared) pAux--;
				
				if (_nodos[nodoActual]->pared && _nodos[vecino]->pared) distancias[vecino] = distancias[nodoActual] + 2;
				else distancias[vecino] = distancias[nodoActual] + 1;

				q.push(pair<int, int> (vecino, pAux));
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
