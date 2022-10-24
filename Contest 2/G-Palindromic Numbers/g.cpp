#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int palindromos(string num, bool menor){

    int n=num.length();
    int total=0;
    for (int i = 0; i < n-1; i++)
        total+=9*int(pow(10,i/2));
    int mid=n/2+n%2;
    int nuevos=stoi(num.substr(0, mid));

    for (int i = mid-1; i >= 0; i--){
         if (num[i]>num[n-i-1]){
             nuevos--;
             break;
             }
             if (num[i]<num[n-i-1])
                break;
    }
    total+=nuevos-(int(pow(10,mid-1)-1));
    
    if (menor){
        for (int i = 0; i < n/2; i++){
            if (num[i]!=num[n-i-1]){
                total++;
                break;
            }
        }
        total--;
    }
    return total+1;
}

bool mayor(string a, string b){
    if (a.length()==b.length())
     return a>b;
 return a.length()>b.length();
}

int main (){
    input;
    int t;
    char a[18],b[18];
    scanf("%d", &t);
     for (int i = 0; i < t; i++){
        scanf("%s %s",&a,&b);
         
        int resultado;
        if (mayor(a,b)){
            resultado =palindromos(a,0)-palindromos(b,1);
        } else{
            resultado =palindromos(b,0)-palindromos(a,1);
        }
             
        printf("Case %d: %d\n",i+1,resultado);
    }
return 0;
}