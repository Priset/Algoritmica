#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

#define MAX_N 10000   

using namespace std; 

int parent[MAX_N];
int rango[MAX_N];

int n, m; 

void init() {
    for(int i=0;  i<= MAX_N; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB);
}

void unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ 
    int origen;
    int destino; 
    double peso; 
    Arista(){}
    bool operator<(const Arista &a) const {
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }
}aristas[MAX_N]; 

Arista MST[MAX_N]; 

int numAristasArbol;
double kruskal(int nroNodos, int nroAristas) {
    
    int origen, destino;
    double peso;

    double total = 0; 

    numAristasArbol = 0; 
    init();  
    sort(aristas,aristas + nroAristas); 

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) { 
            total += peso; 
            unionRango(origen,destino);  
            MST[numAristasArbol] = aristas[i]; 
            numAristasArbol++; 
            
        }
    }
    return total;
}

int main(){
    input;
    while(scanf("%d %d",&n,&m) != EOF) {
        for(int i=0; i<m; i++) {
            scanf("%d %d %lf",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
        }
        printf("%.2lf\n",kruskal(n,m));
        for(int i = 0 ;i <numAristasArbol;i++) {
            cout<<MST[i].origen<<" "<<MST[i].destino<<" "<<MST[i].peso<<endl;
        }
    }

    return 0;
}