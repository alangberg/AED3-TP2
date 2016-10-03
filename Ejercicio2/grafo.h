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
			// este id es solo para despues poder graficar los nodos en forma de grilla en orden
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
		int cantidadNodos() const;
		int cantidadAristas() const;
		const Nodo& iesimoNodo(int i) const;
		const Arista& iesimaArista(int i) const;
		void agregarNodo(int i, int j);
		void agregarArista(int inicio, int fin, int peso);
		void eliminarAristas();
		bool esConexo() const;
		void imprimir(ostream& os) const;

	private:
		vector<Nodo> _nodos;
		vector<Arista> _aristas;
};

void kruskal(Grafo& g);// Modifica al grafo g

#endif