#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <iostream>
#include <utility>
#include <list>
#include <queue>
#include <assert.h>

using namespace std;

class Grafo {
	public:
		struct Nodo {
			// esto es para imprimir a python, despues lo sacamos
			pair<int, int> posicion;
		};

		struct Arista {
			int inicio;
			int fin;
			int peso;
			
			bool operator<(const Arista& a) const{
				if(peso != a.peso)
					return peso < a.peso;
				if(inicio != a.inicio)
					return inicio < a.inicio;
				return fin < a.fin;
			}
		};

		Grafo();
		~Grafo();
		int cantidadNodos();
		int cantidadAristas();
		Nodo iesimoNodo(int i);
		Arista iesimaArista(int i);
		void agregarNodo(int i, int j);
		void agregarArista(int inicio, int fin, int peso);
		void imprimir(ostream& os);
		void eliminarAristas();
		bool esConexo();

	private:
		vector<Nodo> _nodos;
		vector<Arista> _aristas;
};

void kruskal(Grafo& g);

#endif