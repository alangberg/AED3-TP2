#include <vector>
#include <list>
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
	int caminoMinimo(int origen, int destino);

	struct Nodo
	{
		int id;
		int distancia;
		list<pair<int, int> > vecinos; // si pair.first ==1 los nodos son vecinos, si es 2 hay una pared.
		Nodo (int i, int d, list<pair<int,int> > l = list<pair<int, int> > ()) : id(i), distancia (d) {};
		Nodo() :  id(-1), distancia(-1), vecinos( list<pair<int, int> > ()) {};
	};
	
	int _cantnodos;
	vector<Nodo> _nodos;
};