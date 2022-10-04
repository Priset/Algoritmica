#include <iostream>
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

int BIT[1000010];
int longvector;

void update (int pos, int valor ) {
    for(;pos <= longvector ;pos += pos&(-pos)) {
        BIT[pos] += valor;
    }
}    
int query (int pos) {
    int result = 0;
    for(;pos > 0 ;pos -= pos&(-pos)) {
        result += BIT[pos];
    }
    return result;
}
int query2(int inicio, int final) {
    return query (final)-query (inicio-1);
}
int main() {
    input;
    int queries;
    cin>>longvector>>queries;
    vector<int> v(longvector+1,0);
    memset(BIT,0,sizeof BIT);
    while(queries--) {
        char x; int y,z;
        cin>>x;
        if(x == 'F'){
            cin>>y;
            if(v[y]==0){
                v[y]=1;
                update(y,1);
            }else {
                v[y]=0;
                update(y,-1);
            }
        } else{
            cin>>y>>z;
            cout<<query2(y,z)<<endl;
        }
    }
    return 0;
}
