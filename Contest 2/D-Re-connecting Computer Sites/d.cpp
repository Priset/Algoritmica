#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

typedef pair<int, int> arista;
typedef pair<int, arista> conexion;
vector <conexion> conexiones;

int sets;
int padres[10000000];
int rango[10000000];

 void init(int n){
    sets = n;
    for (int i = 0; i <= n; i++){
        padres[i] = i;
        rango[i] = 1;
    }
}
int find(int x){
    if(x == padres[x]){
        return x;
    }else{
        return padres[x] = find(padres[x]);
    }
}
bool mismoSet (int x, int y){
    if(find(x) == find(y)){
        return true;
        }else{
            return false;
            }
}
 void unionRango(int x, int y){
    int xRaiz = find(x);
    int yRaiz = find(y);
        
    if(!mismoSet(xRaiz, yRaiz)){
        rango [yRaiz] += rango[xRaiz];
        padres [xRaiz] = yRaiz;
        sets--;
        }
}
int kruskal(int v){
    int origen, destino, costo, total = 0;
    init(v);
    sort(conexiones.begin(), conexiones.end());
    for(int i = 0; i < conexiones.size(); i++){
        costo = conexiones[i].first;
        origen = conexiones[i].second.first;
        destino = conexiones[i].second. second;
        if(!mismoSet(origen, destino)){
            total += costo;
            unionRango (origen, destino);
        }
    }
    return total;
}
int main(){
    input;
    int V, K, M, u, v, costo, total = 0, T = 0;
    while(scanf("%d", &V) != EOF){
     for (int i = 0; i < V - 1; i++){
         scanf("%d %d %d", &u, &v, &costo);
         total += costo;
     }
     if(T != 0) printf("\n");
     printf("%d\n", total);
     scanf("%d", &K);
     for (int i = 0; i < K; i++){
     scanf("%d %d %d", &u, &v, &costo);
     conexiones.push_back(conexion(costo, arista(u, v)));
     }
     scanf("%d", &M);
     for (int i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &costo);
        conexiones.push_back(conexion(costo, arista(u, v)));
     }
     printf("%d\n", kruskal(V));
     total = 0;
     conexiones.clear();
     T++;
    }
return 0;
}
