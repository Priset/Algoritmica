#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;
#define MAX 100001
int n;
int ans[MAX] ;
int pos[MAX];
int segmentTree[4 * MAX];

void update (int node, int l, int r, int id, int val){
    if(l == r){
        segmentTree[node] += val;
        return;
    }
    int mid = (l+r) / 2;
    if(id > mid){
        update (node * 2 + 1, mid + 1, r, id, val);
    }
        else{
            update (node * 2, l, mid, id, val);
        }
            segmentTree[node] = segmentTree[node * 2] + segmentTree [node * 2+1];
}

int query (int node, int l, int r, int ql, int qr){
    if(r < ql || l > qr){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segmentTree [node] ;
    }
    int mid = (l+r)/2;
    int q1 = query (node*2, l, mid, ql, qr);
    int q2= query(node*2+1, mid+1, r, ql, qr);
    return q1 +q2;
}
int main (){
    input;
    cin>>n;
    for(int i=1;i<=n; i++){
        int k;
        cin>>k;
        pos [k] = i;
    }
    int l= 1;
    int r= n;
    for(int i=1;i<=n; i++){
        if (i%2==1){
            ans[l] = pos[l]-1+query (1, 1, n, 1, pos [l]);
            update (1, 1, n, pos[l], -1);
            l++;
            }
            else{
                ans [r] = n- pos[r] + query(1, 1, n, pos[r], n);
                update (1, 1, n, pos [r], -1);
                r--;
            }
    }
    l = 1;
    r = n;
    for(int i=1;i<=n; i++){
        if (i % 2 == 1)
        cout<<ans [l++]<<endl;
        else
        cout<<ans [r--]<<endl;
    }
    return 0; 
}