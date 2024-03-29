// Trabajo Practico 2, Algoritmos y Estructuras de Datos 3 - FCEN, UBA
// Ejercicio 2

#include "grafo.h"
#include <fstream> // para graficar despues

using namespace std;

enum Direccion { Arriba, Abajo, Izquierda, Derecha };

bool esNumerico(char c){
    return (int)'0'<=c && c<=(int)'9';
}

int cantidadParedesVecinas(int pos_i, int pos_j, vector<string>& matriz){
    int res = 0;
    if(matriz[pos_i][pos_j+1]=='#' || esNumerico(matriz[pos_i][pos_j+1])) res++;
    if(matriz[pos_i][pos_j-1]=='#' || esNumerico(matriz[pos_i][pos_j-1])) res++;
    if(matriz[pos_i+1][pos_j]=='#' || esNumerico(matriz[pos_i+1][pos_j])) res++;
    if(matriz[pos_i-1][pos_j]=='#' || esNumerico(matriz[pos_i-1][pos_j])) res++;
    return res;
}

// requiere que en la (pos_i, pos_j) haya una pared destructible
int idVecino(Direccion dir, int pos_i, int pos_j, vector< vector<int> >& matriz){
    if(dir == Derecha){
        if(matriz[pos_i][pos_j+1] != -1) return matriz[pos_i][pos_j+1];
        if(matriz[pos_i+1][pos_j] != -1) return matriz[pos_i+1][pos_j];
        if(matriz[pos_i-1][pos_j] != -1) return -1; // ya pusimos la arista con este nodo
    } else { // Abajo
        if(matriz[pos_i][pos_j-1] != -1) return matriz[pos_i][pos_j-1];
        if(matriz[pos_i][pos_j+1] != -1) return matriz[pos_i][pos_j+1];
        if(matriz[pos_i+1][pos_j] != -1) return matriz[pos_i+1][pos_j];
    }
}

int ctoi(char c){
    return (int)c - (int)'0';
}

int main(int argc, char** argv) {

    unsigned int F;
    unsigned int C;

    cin >> F >> C;

    cin.ignore(); // descartamos el \n que quedo en el buffer

    string entrada;

    vector<string> matriz_raw;
    vector< vector<int> > matriz_nodos(F, vector<int>(C, -1));

    int contador_nodos = 0;

    Grafo grafo;

    // identificamos todos los nodos
    for(int i = 0; i < F; i++){
        getline(cin, entrada, '\n');
        matriz_raw.push_back(entrada);

        for(int j = 0; j < C; j++){
            if(entrada[j] == '.'){
                matriz_nodos[i][j] = contador_nodos;
                contador_nodos++;
                grafo.agregarNodo(i, j);
            }
        }
    }

    // si no tenemos ningun nodo retornamos -1, no hay nada que unir
    if(grafo.cantidadNodos() == 0){
        cout << -1 << endl;
        return 0;
    }

    // reemplazamos las paredes invalidas por indestructibles
    for(int i = 1; i < F - 1; i++)
        for(int j = 1; j < C - 1; j++)
            if(esNumerico(matriz_raw[i][j]) && cantidadParedesVecinas(i, j, matriz_raw)!=2)
                    matriz_raw[i][j] = '#';

    // recorremos los nodos para conectarlos, en orden desde la esquina superior izq
    for(int i = 0; i < grafo.cantidadNodos(); i++){
        int pos_i = grafo.iesimoNodo(i).posicion.first;
        int pos_j = grafo.iesimoNodo(i).posicion.second;

        char der = matriz_raw[pos_i][pos_j+1];
        char abj = matriz_raw[pos_i+1][pos_j];
        char atr = matriz_raw[pos_i][pos_j-1];

        if(der == '.') 
            grafo.agregarArista(i, matriz_nodos[pos_i][pos_j+1], 0);
        else if(esNumerico(der) && idVecino(Derecha, pos_i, pos_j+1, matriz_nodos)!=-1)
            grafo.agregarArista(i, idVecino(Derecha, pos_i, pos_j+1, matriz_nodos), ctoi(der));

        if(abj == '.') 
            grafo.agregarArista(i, matriz_nodos[pos_i+1][pos_j], 0);
        else if(esNumerico(abj))
            grafo.agregarArista(i, idVecino(Abajo, pos_i+1, pos_j, matriz_nodos), ctoi(abj));

        if(esNumerico(atr) && matriz_raw[pos_i+1][pos_j-1] == '.')
            grafo.agregarArista(i, matriz_nodos[pos_i+1][pos_j-1], ctoi(atr));
    }

    // chequeamos si el grafo es conexo, sino devolvemos -1
    if(!grafo.esConexo()){
        cout << -1 << endl;
        return 0;
    }

    // /* No es parte del Ej */            // Para dibujar los grafos despues en python:
    // /* No es parte del Ej */            ofstream salidaParaGraficar;
    // /* No es parte del Ej */            salidaParaGraficar.open ("salida");
    // /* No es parte del Ej */            grafo.imprimir(salidaParaGraficar);// Original
    // /* No es parte del Ej */            salidaParaGraficar << "*****" << endl;// Separador

    kruskal(grafo);

    // /* No es parte del Ej */            grafo.imprimir(salidaParaGraficar);// AGM
    // /* No es parte del Ej */            salidaParaGraficar.close();

    // contamos el peso total de las aristas y devolvemos la suma == paredes necesarias para conectar todo
    int res = 0;
    for(int i = 0; i < grafo.cantidadAristas(); i++){
        res += grafo.iesimaArista(i).peso;
    }
    cout << res << endl;

    return 0;
}