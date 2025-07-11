#include<bits/stdc++.h>
using namespace std;

void pascals_row(vector<int>& a,int n){
    a[0]=1;
    for (int i = 1; i <=n; i++) {
        a[i]=(a[i-1]*(n-i+1))/i;
    }
}

//  1 5/1 54/2 543/123

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    pascals_row(a,n);
    for (int i = 0; i <n+1; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}