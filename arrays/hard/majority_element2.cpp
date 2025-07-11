// for a given array, return array of numbers whose frequency >n/3(floor  i.e. if n=5 => n/3=1)

#include<bits/stdc++.h>
using namespace std;

// here we can observe that ans array can have at most 2 elements

// // brute force TC: O(n^2) S.C: O(1)
void majority_element(vector<int> &a, vector<int> &ans, int n) {
    for(int i = 0; i < n; i++) {
        if(ans.size()==0 || ans[0]!= a[i]) {
            int count=0;
            for(int j = 0; j < n; j++) {
                if(a[i]==a[j]){count++;}
            }
            if(count>n / 3){ans.push_back(a[i]);}
        }
    }
} 

// better approach using map - TC-O(nlogn) SC-O(n)
// by storing frequencies of each element and if any element's frequency > n/3,immediately pushback it to the ans vector.

// optimized approach - TC: O(n) S.C: O(1)
void majority_element(vector<int> &a, vector<int> &ans, int n){
    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;
    for (int i = 0; i <n; i++) {
        if(cnt1==0 && a[i]!=el2){
            el1=a[i];
            cnt1=1;
        }
        else if(cnt2==0 && a[i]!=el1){
            el2=a[i];
            cnt2=1;
        }
        else if(a[i]==el1){cnt1++;}
        else if(a[i]==el2){cnt2++;}
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1=0; cnt2=0; 
    for (int i = 0; i <n; i++) {
        if(a[i]==el1){cnt1++;}
        if(a[i]==el2){cnt2++;}
    }
    if(cnt1>n/3){ans.push_back(el1);}
    if(cnt2>n/3){ans.push_back(el2);}
}

int main(){
    vector<int> a = {1, 2, 3, 1, 2, 1};
    vector<int> ans;
    majority_element(a, ans, a.size());
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}