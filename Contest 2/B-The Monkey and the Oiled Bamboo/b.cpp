#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int n;
vector<int> rungs;
bool f(int x){
    int dif;
    for (int i = 0; i < n; i++){
        dif=rungs[i+1]-rungs[i];
        if (x<dif)
            return false;
        if (x==dif)
            x--;
    }
    return true;
}

int main(){
    input;
    int t;
    cin>>t;
    for (int i = 0; i < t; i++){
        cin>>n;
        rungs.clear();
        rungs.push_back(0);
        int rung;
        for (int j = 0; j < n; j++){
            cin>>rung;
            rungs.push_back(rung);
        }
        int l=1, r=rung, mid;
        while (l!=r){
            mid=(l+r)/2;
            if (f(mid))
               r=mid;
            else
               l=mid+1;
        }
    cout<<"Case "<<i+1<<": "<<l<<endl;
    }
    return 0;
}

