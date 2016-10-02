#include "grafo.h"

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

// Empieza desde un nodo cualquiera. El vector resultado tiene en la posicion i-esima la distancia desde el
// nodo inicial hasta el nodo i en caso de existir, sino -1.
vector<int> BFS(Grafo& g){
	// como no teniamos lista de vecinos, hay que armarla
	vector< list <int> > vecinos(g.cantidadNodos());
	for(int i = 0; i < g.cantidadAristas(); ++i){
		vecinos[g.iesimaArista(i).inicio].push_back(g.iesimaArista(i).fin);
		vecinos[g.iesimaArista(i).fin].push_back(g.iesimaArista(i).inicio);
	}

	// aca empieza BFS
	vector<int> distancias(g.cantidadNodos(), -1);
	queue<int> cola;

	int nodoInicial = 0;

	cola.push(nodoInicial);
	distancias[nodoInicial] = 0;

	while(!cola.empty()){
		int tope = cola.front();
		cola.pop();
		for(list<int>::iterator i = vecinos[tope].begin(); i != vecinos[tope].end(); ++i){
			if(distancias[*i] == -1){ // si no lo visite
				distancias[*i] = distancias[tope] + 1;
				cola.push(*i);
			}
		}
	}

	return distancias;
}

bool Grafo::esConexo(){ // O(V+E) = O(FC)
	vector<int> distancias = BFS(*this);

	for(vector<int>::iterator i = distancias.begin(); i != distancias.end(); ++i)
		if(*i == -1) // si alguna distancia es infinito => no es conexo
			return false;
		
	return true;
}