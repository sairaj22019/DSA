#include <bits/stdc++.h>
using namespace std;

long long nCr(int n,int r){
    if(r>n) return 0;
    long long res = 1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res/=(i+1);
    }
    return res;
}

void printRowOfPascalTriangle(int n){
    long long res = 1;
    cout<<res<< " ";
    for(int i=1;i<n;i++){
        res*=(n-i);
        res/=(i);
        cout<<res<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;
    printRowOfPascalTriangle(n);
    return 0;
}