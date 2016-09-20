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

	// void leer(int filas, int columnas);
	// int caminoMinimo(int origen, int destino);
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