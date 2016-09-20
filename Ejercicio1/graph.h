#include <vector>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

class Grafo
{
public:
	Grafo();
	//Grafo(int cantnodos);
	void leer(int filas, int columnas);
	int caminoMinimo(int origen, int destino, int P);
	struct Nodo
	{
		int id;
		int distancia;
		vector<pair<int, int> > vecinos; // si pair.first ==1 los nodos son vecinos, si es 2 hay una pared.
		Nodo (int i, int d, vector<pair<int,int> > l = vector<pair<int, int> > ()) : id(i), distancia (d) {};
		Nodo() :  id(-1), distancia(-1), vecinos( vector<pair<int, int> > ()) {};
	};
	
	Nodo* vecino(int id, int i);
	int _cantnodos;
	vector<Nodo*> _nodos;
};