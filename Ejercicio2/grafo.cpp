#include "grafo.h"
#include <assert.h>

Grafo::Grafo(){}

Grafo::~Grafo(){}

int Grafo::cantidadNodos(){
	return this->_nodos.size();
}

int Grafo::cantidadAristas(){
	return this->_aristas.size();
}

Grafo::Nodo Grafo::iesimoNodo(int i){
	assert(0 <= i && i < this->cantidadNodos());
	return this->_nodos[i];
}

Grafo::Arista Grafo::iesimaArista(int i){
	assert(0 <= i && i < this->cantidadAristas());
	return this->_aristas[i];	
}

void Grafo::agregarNodo(int i, int j){
	Grafo::Nodo n;
	n.posicion.first = i;
	n.posicion.second = j;
	this->_nodos.push_back(n);
}

void Grafo::agregarArista(int inicio, int fin, int peso){
	Grafo::Arista a;
	a.inicio = inicio;
	a.fin = fin;
	a.peso = peso;
	this->_aristas.push_back(a);
}

void Grafo::imprimir(ostream& os){
	os << this->cantidadNodos() << " " << this->cantidadAristas() << endl;

	for(int i = 0; i < this->cantidadNodos(); i++)
		os << i << " " << this->iesimoNodo(i).posicion.first << " " << this->iesimoNodo(i).posicion.second << endl;
	
	for(int i = 0; i < this->cantidadAristas(); i++)
		os << this->iesimaArista(i).inicio << " " 
			<< this->iesimaArista(i).fin << " " 
			<< this->iesimaArista(i).peso << endl;
}

void Grafo::eliminarAristas(){
	this->_aristas.clear();
}

bool Grafo::esConexo(){ // O(V E)
	vector<bool> algunVecino(this->cantidadNodos(), false);

	for(int i = 0; i < this->cantidadAristas(); i++){
		algunVecino[iesimaArista(i).inicio] = true;
		algunVecino[iesimaArista(i).fin] = true;
	}

	bool res = true;

	for(int i = 0; i < this->cantidadNodos(); i++)
		res = res && algunVecino[i];

	return res;
}