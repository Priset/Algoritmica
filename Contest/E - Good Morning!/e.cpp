#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

int t, in, ans, res;
string s;
char keyboard [4][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {-1,0,-1}
};

void dfs(int x, int y, int current){
    if (current == s.length()) {
        int currDig = res;
        if (abs(ans - in) > abs(currDig - in)){
            ans = currDig;
        }
        return;
    }
    for (int i=x; i < 4; i++) {
        for (int j=y; j < 3 ;j++){
            if (keyboard [i] [j] == -1) {
                continue;
            }
            res=res*10+keyboard[i][j];
            dfs(i, j, current+1);
            res=res/10;
        }
    }
    return;
}

int main(){
    input;
    cin >> t;
    while (t--) {
        ans=1;
        cin>>s;
        in=stoi(s);
        dfs (0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}