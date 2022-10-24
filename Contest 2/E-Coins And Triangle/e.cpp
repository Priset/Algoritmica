#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

long long n; 

bool f(int k) {
        return k*(k+1)/2<=n;
}

int binarySearch() {
    long long left = 0;
    long long right = 50000;
    long long mid = (left + right) /2; 
    while( left<=right ) {
        if(f(mid)) {
            left = mid+1;
        }
        else{
            right = mid-1;
        }
        mid = (left+right)/2;
    }
    return mid;
}

int main() {
    input;
    int t;
    cin>>t;
    int res[t];
    for (int i =0; i<t; i++) {
        cin>>n;
        res[i]=binarySearch();
    }
    for (int i =0; i<t; i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}