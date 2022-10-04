#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

 int main(){
    input;
    int n,m; scanf("%d %d",&n,&m);
    vector<pair<int, int> > v(m);
    for (int i=0;i<m;i++) scanf("%d %d",&v[i].first,&v[i].second);

    int res=0;
    for (int mask=0;mask<(1<<n);mask++){
        bool sw=true;
        for (int i=0;i<v.size();i++){
            if(mask&(1<<v[i].first) && mask&(1<<v[i].second)) sw=false;
            res+=sw;
            }
        }
    printf("%d\n", res);

    return 0;
 }
