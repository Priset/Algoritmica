#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

int status [21] [21], counter = 0;

void fuerzaBruta (int k, int n, int arr[]) {
    if (k == n){
        vector<short> vec;
        bool run = true;
        for(int i = 0; i<n; i++)
            if (arr[i]) vec.push_back(i + 1);

        for (int i= 0; i < vec.size() && run; i++)
            for (int j = i; j < vec.size() && run; j++)
                if (status [vec [i]] [vec [j]]) {
                    ++counter;
                    run = false;
                }
    } else{
        arr[k]=0;
     fuerzaBruta (k + 1, n, arr);
        arr[k]=1;
     fuerzaBruta (k + 1, n, arr);
    }
}
int main() {
    input;
    int n, m;
    cin>>n>>m;
    int arr[20] = {0};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        if (a > b) swap(a, b);
        status[a][b] = 1;
    }
 fuerzaBruta (0, n, arr);
    cout<<pow(2, n)-counter<<'\n';
}