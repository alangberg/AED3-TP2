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

int pos_vecino(vector<vector<int> > const &matriz, pair<int, int> pos, Direccion dir) {
	switch (dir) {
	case Arriba:
		if (matriz[pos.first + 1][pos.second] != -1) return matriz[pos.first + 1][pos.second];
		if (matriz[pos.first][pos.second - 1] != -1) return matriz[pos.first][pos.second - 1];
		if (matriz[pos.first][pos.second + 1] != -1) return matriz[pos.first][pos.second + 1];
		break;
	case Abajo:
		if (matriz[pos.first - 1][pos.second] != -1) return matriz[pos.first - 1][pos.second];
		if (matriz[pos.first][pos.second - 1] != -1) return matriz[pos.first][pos.second - 1];
		if (matriz[pos.first][pos.second + 1] != -1) return matriz[pos.first][pos.second + 1];
		break;
	case Izquierda:
		if (matriz[pos.first + 1][pos.second] != -1) return matriz[pos.first + 1][pos.second];
		if (matriz[pos.first - 1][pos.second] != -1) return matriz[pos.first - 1][pos.second];
		if (matriz[pos.first][pos.second + 1] != -1) return matriz[pos.first][pos.second + 1];
		break;
	case Derecha:
		if (matriz[pos.first + 1][pos.second] != -1) return matriz[pos.first + 1][pos.second];
		if (matriz[pos.first][pos.second - 1] != -1) return matriz[pos.first][pos.second - 1];
		if (matriz[pos.first - 1][pos.second] != -1) return matriz[pos.first - 1][pos.second];
		break;
	}
	return -1;
}

// bool pertenece(vector<Posicion> const &v, Posicion const &p) {
// 	for (int i = 0; i < v.size(); i++) {
// 		if (v[i].x == p.x && v[i].y == p.y) return true;
// 	}
// 	return false;
// }

int main(int argc, char** argv) {

	unsigned int F;
	unsigned int C;

	string entrada;

	getline(cin, entrada, '\n');
	vector<int> v;

	split(entrada, ' ', v);

	F = v[0];
	C = v[1];

	vector<string> matriz_raw;
	vector<vector<int> > matriz_nodos (F, vector<int>(C, -1));

	int contador_nodos = 0;

	for (int i = 0; i < F; i++) {
		getline(cin, entrada, '\n');
		matriz_raw.push_back(entrada);

		for (int j = 0; j < C; j++) {
			if (entrada[j] == '.') {
				matriz_nodos[i][j] = contador_nodos;
				contador_nodos++;
			}
		}
	}

	Grafo grafo;

	cout << "asd" << endl;

	for (int i = 1; i < F - 1; i++) {
		for (int j = 1; j < C - 1; j++) {
			char c = matriz_raw[i][j];
			if (c == '.') {
				char arr = matriz_raw[i - 1][j];
				char abj = matriz_raw[i + 1][j];
				char izq = matriz_raw[i][j - 1];
				char der = matriz_raw[i][j + 1];

				Grafo::Nodo* n = grafo.nuevoNodo();
				n->id = matriz_nodos[i][j];
				if (arr == '.') n->vecinos.push_back(pair<int, int>(0, matriz_nodos[i - 1][j]));
				else if ((int)arr >= 49 && (int)arr <= 57) n->vecinos.push_back(pair<int, int>((int)arr - 48, pos_vecino(matriz_nodos, pair<int, int>(i - 1, j), Abajo) ));

				if (abj == '.') n->vecinos.push_back(pair<int, int>(0, matriz_nodos[i + 1][j]));
				else if ((int)abj >= 49 && (int)abj <= 57) n->vecinos.push_back(pair<int, int>((int)abj - 48, pos_vecino(matriz_nodos, pair<int, int>(i + 1, j), Arriba) ));
				
				if (izq == '.') n->vecinos.push_back(pair<int, int>(0, matriz_nodos[i][j - 1]));
				else if ((int)izq >= 49 && (int)izq <= 57) n->vecinos.push_back(pair<int, int>((int)izq - 48, pos_vecino(matriz_nodos, pair<int, int>(i, j - 1), Derecha) ));

				if (der == '.') n->vecinos.push_back(pair<int, int>(0, matriz_nodos[i][j + 1]));
				else if ((int)der >= 49 && (int)der <= 57) n->vecinos.push_back(pair<int, int>((int)der - 48, pos_vecino(matriz_nodos, pair<int, int>(i, j + 1), Izquierda) ));
			}
		}
	}

	// cout << grafo.kruskal() << endl;

	grafo.imprimir();

	return 0;
}
