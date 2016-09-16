#include <iostream>
#include <vector>
#include <map>

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
	int buscarMin(int minimos[], vector<int> zonaSegura);
	int caminoMinimo(int origen, vector<int>& v);
	//~Grafo();


private:
	int _cantnodos;
	vector<vector<int> > _matriz;

};

Grafo::Grafo(){
	_cantnodos= 0;
	_matriz= (vector<vector<int> > ());
}

Grafo::Grafo(int cantnodos): _cantnodos(cantnodos){
   vector<int> v (cantnodos,0);

   vector<vector<int> > matriz (cantnodos,v);
    _matriz = matriz;
}

/*ostream& operator<<(ostream& out, const Grafo a){
    return a.mostrarGrafo(out);
}



            

ostream& Grafo::mostrarGrafo(ostream& os) const{
cout<<"------------------"<<endl;

    for(int i=0;i<_cantnodos;i++){
        os<<"[";
        for(int j=0;j<_cantnodos;j++){
        if(j!=_cantnodos-1){
        os<<_matriz[i][j]<<",";
        }else{
        os<<_matriz[i][j]<<"]"<<endl;
        }
        }
    }
    cout<<"------------------";

}*/