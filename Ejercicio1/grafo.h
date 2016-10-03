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
	int cant_aristas = 0;
	for (unsigned int i = 0; i < this->_nodos.size(); i++) {
		for (unsigned int j = 0; j < this->_nodos[i]->vecinos.size(); j++) cant_aristas++;
	}

	cant_aristas /= 2;
	
	cout << this->_cantnodos << ' ' << cant_aristas << endl;

	for (unsigned int i = 0; i < this->_nodos.size(); i++) {
		for (unsigned int j = 0; j < this->_nodos[i]->vecinos.size(); j++) {
			if (this->_nodos[i]->id > this->_nodos[i]->vecinos[j]) cout << this->_nodos[i]->id << ' ' << this->_nodos[i]->vecinos[j] << " 1" << endl;
		}
	}
}

int Grafo::caminoMinimo(int origen, int destino, int P){
	
	vector<vector<int> > distancias(P+1, vector<int>(this->_cantnodos, -1));

	distancias[P][origen] = 0;

	queue<pair<int, int> > q;
	q.push(pair<int, int>(origen, P));
	
	int j=0;
	while(!q.empty()){
		pair<int, int> actual = q.front();
		q.pop();

		int nodoActual = actual.first;
		int pAux;

		for(int i = 0; i < _nodos[nodoActual]->vecinos.size(); i++) {
			pAux = actual.second;
			int vecino = _nodos[nodoActual]->vecinos[i];

			if(_nodos[vecino]->pared && pAux > 0) pAux--;
			
			if(distancias[pAux][vecino] == -1 && (!(_nodos[vecino]->pared) || pAux >= 0 )) {
				if(_nodos[nodoActual]->pared && _nodos[vecino]->pared) distancias[pAux][vecino] = distancias[pAux+1][nodoActual] + 2;
				else {
					if(_nodos[vecino]->pared) distancias[pAux][vecino] = distancias[pAux+1][nodoActual] + 1;
					else distancias[pAux][vecino] = distancias[pAux][nodoActual] + 1;
				}

				q.push(pair<int, int> (vecino, pAux));

				for (int j = 0; j < distancias.size(); ++j) {
					for (int k = 0; k < distancias[j].size(); ++k) {
						cout << ' ';
						if(distancias[j][k] != -1 && distancias[j][k] < 10) cout << "+";
						cout << distancias[j][k];
					}
					cout << endl;
				}
				cout << endl;
			}
		}
		j++;
	}

	int minimo = -1;
	for (int i = 0; i < P+1; ++i) {
		if(distancias[i][destino] != -1 && distancias[i][destino] < minimo) {
			minimo = distancias[i][destino];
		}
	}
	return minimo;

}

// Grafo::Nodo* Grafo::vecino(int id, int i){
// 	int s = _nodos[id]->vecinos[i].second;
// 	return _nodos[s];
// }
