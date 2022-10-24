#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

long long int deepak(long long int m, string s){
    long long int add = 0;
    for(int i = m; i >= 0; i--){
        long long int v = (int(s[i])-int('0')+add)%10;
        if(v==0)
            continue;
        add+=10-v;
        }
        return add;
    }
    
int main(){
    
    input;
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin >> a >> b;
        string str;
        cin >> str;
        long long int l=0, r=a-1, ans=0;
        while(l<=r){
            long long int m=(l+r)/2;
            if(deepak(m,str)>b)
               r=m-1;
            else
            {
               ans = m+1;
               l=m+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
