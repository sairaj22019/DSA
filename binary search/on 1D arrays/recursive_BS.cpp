// for a given sorted array, find the index of a given element using recursive binary search

#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> &a,int target,int left , int right){
    if(left>right){ 
        return -1; // target not found
    }
    int mid=left+(right-left)/2;
    if(a[mid]==target){ 
        return mid; 
    }
    else if(a[mid]<target){
        return BS(a,target,mid+1,right);
    }
    else{
        return BS(a,target,left,mid-1);
    }
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int ans= BS(a,target,1,a.size()-1);
    return 0;
}