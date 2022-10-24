#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 10000000
using namespace std;

struct Node{
     double x, y;
};

double distancia(Node* a, Node* b){
     return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

int menor(vector<double> dist, vector<bool> vis){
    double menorDistancia = INF;
    int u;
    for (int i = 0; i < dist.size(); i++){
         if (vis[i]){
             continue;
         }
         if (dist[i] < menorDistancia){
            menorDistancia = dist [i];
             u = i;
         }
    }
     return u;
}
double prim(vector<Node*> vertices){
     int V = vertices.size();
     int conexion = -1;

    vector<double> dist(V, INF);
    vector<bool> vis (V, false);
    double cost = 0;

    dist[0] = 0;
    while (conexion != V-1){
        int u = menor (dist, vis);
        cost += dist[u];
        vis[u] = true;
        conexion++;

        for (int v = 0; v < V; v++){
             if (u == v)
                 continue;
            double d = distancia(vertices[u], vertices[v]);
            if (!vis[v] && d < dist[v]){
                dist[v] = d;
            }
        }
    }
    return cost;
}
int main(){
    input;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<Node*> vertices;
        
        for (int j = 0; j < n; j++){
            double x, y;
            cin >> x;
            cin >> y;
            
            Node* p = new Node();
            p->x = x;
            p->y = y;
            vertices.push_back(p);
        }
        double costoMenor = prim(vertices);
        if (i == 0){
            printf("%.2f\n", costoMenor);
        }else{
            printf("\n%.2f\n", costoMenor);
        }
    }
    return 0;
}
