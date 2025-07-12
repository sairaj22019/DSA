// given a 2d array in which all rows are sorted and all columns are sorted

#include<bits/stdc++.h>
using namespace std;

// brute   TC-O(n*m)
// traverse entire 2d array

// better  TC-O(nlogm)
// perform binary search for each row

// optimal    TC-O(n+m)
pair<int,int> search(vector<vector<int>>& a,int k){
    int n=a.size();
    int m=a[0].size();
    int row=0,col=m-1;
    while(row<n && col>=0){
        if(a[row][col]==k){return {row,col};}
        else if (a[row][col]<k){row++;}
        else{col--;}
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> a = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int k = 5;
    pair<int,int> ans=search(a,k);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}