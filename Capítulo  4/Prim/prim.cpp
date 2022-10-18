#include <vector>
#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

class Grafo
{
public:
    Grafo();
    Grafo(int nodos);
    vector< vector<int> > prim();
private:
    const int INF = numeric_limits<int>::max();
    int cantidadNodos; 
    vector< vector<int> > adyacencia; 
};

Grafo::Grafo()
{
}

Grafo::Grafo(int nodos)
{
    this->cantidadNodos = nodos;
        this->adyacencia = vector< vector<int> > (cantidadNodos);

        for(int i = 0; i < cantidadNodos; i++)
            adyacencia[i] = vector<int> (cantidadNodos, INF);
}

vector< vector<int> > Grafo :: prim(){
    vector< vector<int> > adyacencia = this->adyacencia;
    vector< vector<int> > arbol(cantidadNodos);
    vector<int> markedLines;
    vector<int> :: iterator vectorIterator;

    for(int i = 0; i < cantidadNodos; i++)
        arbol[i] = vector<int> (cantidadNodos, INF);

    int padre = 0;
    int hijo = 0;
    while(markedLines.size() + 1 < cantidadNodos){
        padre = hijo;
        markedLines.push_back(padre);
        for(int i = 0; i < cantidadNodos; i++)
            adyacencia[i][padre] = INF;

        int min = INF;
        for(vectorIterator = markedLines.begin(); vectorIterator != markedLines.end(); vectorIterator++)
            for(int i = 0; i < cantidadNodos; i++)
                if(min > adyacencia[*vectorIterator][i]){
                    min = adyacencia[*vectorIterator][i];
                    padre = *vectorIterator;
                    hijo = i;
                }

        arbol[padre][hijo] = min;
        arbol[hijo][padre] = min;
    }
    return arbol;
}