#include <vector>
#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

vector< pair <int,pair<int, int>> > grafo[100000];
vector< pair <int,pair<int, int>> > grafoMST[100000];
bool visitados[100000];

int Prim(int verticeInicial){
    multiset< pair<int,pair<int, int>> > colaPrioridad;
    colaPrioridad.insert(make_pair(0, make_pair(verticeInicial,verticeInicial))); 
    int expansionMST = 0;

    while (!colaPrioridad.empty()){
        pair <int,pair<int, int>> verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin()); 

        pair<int,int> verticeDireccionado = verticeActual.second; 
        int peso = verticeActual.first; 

        int verticeBegin = verticeDireccionado.first;
        int vertice = verticeDireccionado.second;

        if (!visitados[vertice]){ 
            visitados[vertice] = true;
            expansionMST += peso;
            
            grafoMST[verticeBegin].push_back(make_pair(peso,make_pair(verticeBegin,vertice)));
            
            for (int i = 0; i < grafo[vertice].size(); ++i){ 
                pair<int, int> verticeVecino = grafo[vertice][i].second;
                int pesoVecino = grafo[vertice][i].first;
                colaPrioridad.insert(make_pair(pesoVecino, verticeVecino)); 
            }
        }   
    }

    return expansionMST; 
}



int main()
{
    input;
    int vertices, aristas;
    cin >> vertices >> aristas;
    for (int i = 0; i < aristas; i++)
    {
        int ini,fin,peso; 
        cin>>ini>>fin>>peso;
        grafo[ini].push_back(make_pair(peso,make_pair(ini,fin)));
        grafo[fin].push_back(make_pair(peso,make_pair(fin,ini)));
    }
    cout <<  Prim(0) << endl;

    for (int i = 0; i < vertices; i++){
        for(int j = 0 ;j < grafoMST[i].size();j++){
            cout<<grafoMST[i][j].first<<" "<<grafoMST[i][j].second.first<<" "<< grafoMST[i][j].second.second<<endl;
        }
    }

    return 0;
}


