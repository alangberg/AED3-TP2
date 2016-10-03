// Trabajo Practico 2, Algoritmos y Estructuras de Datos 3 - FCEN, UBA
// Ejercicio 2

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include "grafo.h"

using namespace std;

enum Direccion { Arriba, Abajo, Izquierda, Derecha };

void split(const string &s, char delim, vector<int> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(atoi(item.c_str()));
	}
}

int main(int argc, char** argv) {

	unsigned int F;
	unsigned int C;
	unsigned int P;

	string entrada;

	getline(cin, entrada, '\n');
	vector<int> v;

	split(entrada, ' ', v);

	F = v[0];
	C = v[1];
	P = v[2];

	vector<string> matriz_raw;
	vector<vector<int> > matriz_nodos (F, vector<int>(C, -1));

	int nodo_o;
	int nodo_x;

	int contador_nodos = 0;
	for (int i = 0; i < F; i++) {
		getline(cin, entrada, '\n');
		matriz_raw.push_back(entrada);

		for (int j = 0; j < C; j++) {
			if (entrada[j] == 'o') nodo_o = contador_nodos;
			else if (entrada[j] == 'x') nodo_x = contador_nodos;
			
			if (i > 0 && i < F - 1 && j > 0 && j < C - 1 ) {
				matriz_nodos[i][j] = contador_nodos;
				contador_nodos++;
			}
		}
	}

	Grafo grafo;

	for (int i = 1; i < F - 1; i++) {
		for (int j = 1; j < C - 1; j++) {
			Grafo::Nodo* n = grafo.nuevoNodo();
			if(matriz_raw[i][j] == '#') n->pared = true;
			n->id = matriz_nodos[i][j];

			if (i - 1 > 0) n->vecinos.push_back(matriz_nodos[i - 1][j]);
			if (i + 1 < F - 1) n->vecinos.push_back(matriz_nodos[i + 1][j]);
			if (j - 1 > 0) n->vecinos.push_back(matriz_nodos[i][j - 1]);
			if (j + 1 < C - 1) n->vecinos.push_back(matriz_nodos[i][j + 1]);
		}
	}

	// grafo.imprimir();

	cout << grafo.caminoMinimo(nodo_o, nodo_x, P) << endl;


	return 0;
}
	