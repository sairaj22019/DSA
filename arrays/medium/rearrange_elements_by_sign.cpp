// given array contains equal number of positive and negative integers. rearrange them such that all consequtive element have opposite sign and the order of nums having same sign should not be altered

#include<bits/stdc++.h>
using namespace std;

// // brute force TC-o(n+n)  SC-O(n){excluding the ans array}
// vector<int> rearrange(vector<int>& a){
//     int n=a.size();
//     vector<int>pos,neg;
//     for (int i = 0; i <n; i++) {
//         if(a[i]>0){pos.push_back(a[i]);}
//         else{neg.push_back(a[i]);}
//     }
//     vector<int> ans(n);
//     for (int i = 0; i <n/2; i++) {
//         ans[2*i]=pos[i];
//         ans[2*i+1]=neg[i];
//     }
//     return ans;
// }
//optimal TC-o(n)  SC-O(1){excluding the ans array}
vector<int> rearrange(vector<int>& a){
    int n=a.size();
    vector<int> ans(n);
    int posindex=0,negindex=1;
    for (int i = 0; i <n; i++) {
        if(a[i]>0){
            ans[posindex]=a[i];
            posindex+=2;
        }
        else{
            ans[negindex]=a[i];
            negindex+=2;
        }
    }
    return ans;
}

int main(){
    vector<int> a={7,-2,4,7,9,-3,2,1,-4,-2,-9,-5};
    vector<int> ans=rearrange(a);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}