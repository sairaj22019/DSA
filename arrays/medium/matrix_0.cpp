#include<bits/stdc++.h>
using namespace std;

// brute force TC-O(n*m*(n+m))  SC-O(1)
void matrix_0(vector<vector<int>>& a,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                for(int k=0;k<n;k++){a[k][j]=0;}
                for(int k=0;k<m;k++){a[i][k]=0;}
            }
        }
    }
}


// better  TC-O(2*n*m)  SC-O(n+m)
void matrix_0(vector<vector<int>>& a,int n,int m){
    vector<int> row(n,1),col(m,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                row[i]=0;
                col[j]=0;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==0 || col[j]==0){a[i][j]=0;}
        }
    }
}


// optimal  TC-O(n*m)  SC-O(1)
void matrix_0(vector<vector<int>>& a,int n,int m){
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]==0){
                a[i][0]=0;
                if(j==0){col0=0;}
                else{a[0][j]=0;}
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][0]==0 || a[0][j]==0){a[i][j]=0;}
        }
    }
    if(a[0][0]==0){
        for(int j=1;j<m;j++){a[0][j]=0;}
    }
    if(col0==0){
        for(int i=0;i<n;i++){a[i][0]=0;}
    }
}

int main(){
    vector<vector<int>> a={{1,0,0,1,1},{0,1,1,1,0},{1,1,1,1,1},{1,1,1,0,1}};
    matrix_0(a,a.size(),a[0].size());
    return 0;
}