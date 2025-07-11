//for a given array , retrun all the leaders in array in same order as they were in array
// leaders are the number which are greater than all numbers to right of it
#include<bits/stdc++.h>
using namespace std;

// brute- TC-O(n^2)  SC-O(n)
// for every element traverse linerly to right and if there no number greater than it

// optimal TC-O(n+n)  SC-O(n)
vector<int> leaders(vector<int>& a){
    int n=a.size();
    int max=INT_MIN;
    vector<int> ans;
    for (int i = n-1; i >=0; i--) {
        if(a[i]>max){
            ans.push_back(a[i]);
            max=a[i];
        }
    }
    reverse(a.begin(),a.end());// if leader were to be returned in sorted oreder, we dont have to reverse
    return ans;
}
int main(){
    vector<int> a={10,22,12,3,0,6};
    vector<int> ans=leaders(a);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}