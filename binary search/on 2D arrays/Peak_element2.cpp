// find any peak element in a 2d array(no 2 adjecent elements are same). peak element is an element which is grater than its adjescent elements(if the element lies on border , you dont have to check beyond border)

#include<bits/stdc++.h>
using namespace std;

// brute   TC-O(n*m*4)
// traverse entire 2d array and check 4 conditions with 4 adjecent element
// in above method at each element we check for 4 conditions, this leads to worst case TC-O(n*m*4)
// better - we can make a little optimisation to this worst case.
// here max element of array would surely be peak element , so we can traverse entire array to find max element, this gives a TC-O(n*m)

// optimal  TC-O(nlogm) SC-O(1)
// here we apply binary search on columns and try to find max element(as max element is peak) and return if we find any peak in this process
int maxInd(vector<vector<int>>& a,int n, int m, int col){
    int ind=-1,max=-1;
    for (int i = 0; i <n; i++) {
        if(a[i][col]>max){
            max=a[i][col];
            ind=i;
        }
    }
    return ind;
}

pair<int,int> peak(vector<vector<int>>& a){
    int n=a.size();
    int m=a[0].size();
    int low=0,high=m-1;
    while(low<high){
        int mid=high+low/2;
        int maxRowIndex = maxInd(a,n,m,mid);
        int left = (mid-1>=0)? a[maxRowIndex][mid-1] : -1;
        int right = (mid+1<=n)? a[maxRowIndex][mid+1] : -1;
        if(a[maxRowIndex][mid]>left && a[maxRowIndex][mid]>right){
            return {maxRowIndex,mid};
        }else if(a[maxRowIndex][mid]<left){high=mid-1;}
        else{low=mid+1;}
    }
    return {-1,-1};
}


int main(){
    vector<vector<int>> a = {{10,20,15},{21,30,14},{7,16,32}};
    pair<int,int> ans= peak(a);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}