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

void agregarNodosVecinos(Grafo::Nodo* nodo, const vector<vector<int> > &matriz, pair<int, int> pos, Direccion dir) {
	
	if ((pos.first - 1 > 0) && matriz[pos.first - 1][pos.second] != -1 && dir != Arriba) nodo->vecinos.push_back(pair<int, int>(2, matriz[pos.first - 1][pos.second]));
	if ((pos.first + 1 < matriz.size()) && matriz[pos.first + 1][pos.second] != -1 && dir != Abajo) nodo->vecinos.push_back(pair<int, int>(2, matriz[pos.first + 1][pos.second]));
	if ((pos.second - 1 > 0) && matriz[pos.first][pos.second - 1] != -1 && dir != Izquierda) nodo->vecinos.push_back(pair<int, int>(2, matriz[pos.first][pos.second - 1]));
	if ((pos.second + 1 < matriz[0].size()) && matriz[pos.first][pos.second + 1] != -1 && dir != Derecha) nodo->vecinos.push_back(pair<int, int>(2, matriz[pos.first][pos.second + 1]));

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

	int contador_nodos = 0;

	int nodo_o;
	int nodo_x;

	for (int i = 0; i < F; i++) {
		getline(cin, entrada, '\n');
		matriz_raw.push_back(entrada);

		for (int j = 0; j < C; j++) {
			if (entrada[j] == '.') {
				matriz_nodos[i][j] = contador_nodos;
				contador_nodos++;
			} else if (entrada[j] == 'o') {
				matriz_nodos[i][j] = contador_nodos;
				nodo_o = contador_nodos;
				contador_nodos++;
			} else if (entrada[j] == 'x') {
				matriz_nodos[i][j] = contador_nodos;
				nodo_x = contador_nodos;
				contador_nodos++;
			}
		}
	}

	Grafo grafo;

	for (int i = 1; i < F - 1; i++) {
		for (int j = 1; j < C - 1; j++) {
			char c = matriz_raw[i][j];
			if (c == '.' || c == 'o' || c == 'x') {
				char arr = matriz_raw[i - 1][j];
				char abj = matriz_raw[i + 1][j];
				char izq = matriz_raw[i][j - 1];
				char der = matriz_raw[i][j + 1];

				Grafo::Nodo* n = grafo.nuevoNodo();
				n->id = matriz_nodos[i][j];
				if (arr == '.' || arr == 'o' || arr == 'x') n->vecinos.push_back(pair<int, int>(1, matriz_nodos[i - 1][j]));
				else agregarNodosVecinos(n, matriz_nodos, pair<int, int>(i - 1, j), Abajo);
				
				if (abj == '.' || abj == 'o' || abj == 'x') n->vecinos.push_back(pair<int, int>(1, matriz_nodos[i + 1][j]));
				else agregarNodosVecinos(n, matriz_nodos, pair<int, int>(i + 1, j), Arriba);
				
				if (izq == '.' || izq == 'o' || izq == 'x') n->vecinos.push_back(pair<int, int>(1, matriz_nodos[i][j - 1]));
				else agregarNodosVecinos(n, matriz_nodos, pair<int, int>(i, j - 1), Derecha);

				if (der == '.' || der == 'o' || der == 'x') n->vecinos.push_back(pair<int, int>(1, matriz_nodos[i][j + 1]));
				else agregarNodosVecinos(n, matriz_nodos, pair<int, int>(i, j + 1), Izquierda);
			}
		}
	}

	cout << grafo.caminoMinimo(nodo_o, nodo_x, P) << endl;


	return 0;
}
	