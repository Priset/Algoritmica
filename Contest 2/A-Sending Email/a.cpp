#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define inf 1e8
using namespace std;

const int N= 1e5+10;
int T, n, m, s, t, u, v, w, counter, dist[N], h[N], vis[N];

struct node{
     int end, dis, current;
}e[2*N];

queue<int> q;
void add(int start, int end, int dis){
    e[counter].current = h[start];
    e[counter].end = end;
    e[counter].dis = dis;
    h[start] = counter++;
 }

 int dijkstra(){
     for (int i = 0; i < n; i++){
         dist[i] = inf;
         vis[i] = 0;
     }
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for (int i = h[u]; i != -1; i = e[i].current){
             if(dist[u] + e[i].dis < dist[e[i].end]){
                 dist[e[i].end] = dist[u]+e[i].dis;
                if(!vis[e[i].end]){
                    vis[e[i].end] = true;
                    q.push(e[i].end);
                }
             }
        }
        vis[u] = 0;
    }if(dist[t] == inf){
        return -1;
    }else{
        return dist[t];
    }
}
int main(){
    input;
    scanf( "%d", &T);
    for (int i = 1; i <= T; i++){
        counter = 0;
        memset(h, -1, sizeof(h));
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for (int j = 1; j <= m; j++){
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        int ans = dijkstra();
        if(ans == -1){
            printf("Case #%d: unreachable\n", i);
        }else{
            printf("Case #%d: %d\n",i, ans);
        }
    }
    return 0;
}
