#include <iostream>
#include <vector>
#include <map>
#include "auxiliares.h"
using namespace std;

#define INF 100000

class Grafo
{
public:
	Grafo();
	Grafo(int cantnodos);
	void leer(int cantAristas);
	void mostrar() const;
	ostream& mostrarGrafo(ostream&) const;
	int caminoMinimo(int origen, vector<int>& v);
	//~Grafo();


private:
	int _cantnodos;
	vector<vector<int> > _matriz;
	int buscarMin(int minimos[], vector<bool> zonaSegura);

};

