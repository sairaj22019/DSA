#include<bits/stdc++.h>
using namespace std;

// brute force- TC-O(n^2)  SC-O(n^2)
// just create a new matrix and fill it with rotated values

// optimised approach- TC-O(n^2)  SC-O(1)
void rotate(vector<vector<int>>& a) {
    int n=a.size();
    for(int i=0;i<=(n-1)/2;i++){
        for(int j=0;j<(n)/2;j++){
            int temp=a[i][j];
            a[i][j]=a[n-j-1][i];
            a[n-j-1][i]=a[n-i-1][n-j-1];
            a[n-i-1][n-j-1]=a[j][n-i-1];
            a[j][n-i-1]=temp;
        }
    }
}


// optimal approach- TC-O(n^2)  SC-O(1)
// transpose the given matrix and reverse every row of it 
void rotate(vector<vector<int>>& a,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(a[i][j],a[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(a[i].begin(),a[i].end());
    }
}

int main(){
    vector<vector<int>> a = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    // The below is the method to define 2d vector
    // int n = a.size();
    // int m = a[0].size();
    // vector<vector<int>> v(n,vector<int> (m));
    rotate(a, a.size());
    for (auto row:a) {
        for (int val:row) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}