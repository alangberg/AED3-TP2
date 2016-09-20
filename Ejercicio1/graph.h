#include <vector>
#include <list>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

class Grafo {
public:
	~Grafo();
	Grafo();
	//Grafo(int cantnodos);

	Nodo* nuevoNodo();

	//void leer(int filas, int columnas);
	// int caminoMinimo(int origen, int destino);
	void imprimir();

	struct Nodo {
		Nodo (int i, int d, list<pair<int,int> > l = list<pair<int, int> > ()) : id(i), distancia (d) {};
		Nodo() :  id(-1), distancia(-1), vecinos( list<pair<int, int> > ()) {};
		
		int id;
		vector<pair<int, int> > vecinos; // si pair.first ==1 los nodos son vecinos, si es 2 hay una pared.
	};
	
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
}

Grafo::~Grafo() {
	for (vector<Nodo*>::iterator i = this->_nodos.begin(); i < this->_nodos.end(); i++) {
		delete this->_nodos[i];
	}
}

void Grafo::imprimir() {
	cout << '{';
	for (vector<Nodo*>::iterator i = this->_nodos.begin(); i < this->_nodos.end(); i++) {
		cout << this->_nodos[i]->id << " [ ";
		for (vector<pari<int, int> >::iterator j = this->_nodos[i]->vecinos.begin(); i < this->_nodos[i]->vecinos.end(); i++) {
			cout << "(" << this->_nodos[i]->vecinos[j].first() << this->_nodos[i]->vecinos[j].second() << ") ";
		}
		cout << "] " << endl;
	}
	cout << "} " << endl;

}