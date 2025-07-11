// an array is given.find the indices of two elements whose sum is equal to k
// given that there is exactly one answer for question

#include<bits/stdc++.h>
using namespace std;
// // brute force  TC-O(n^2)  SC-O(1)
// pair<int,int> twoSum(vector<int>& a,int k){
//     int n=a.size();
//     for (int i = 0; i <n; i++) {
//         for (int j = i+1; j <n; j++) {
//             if(a[i]+a[j]==k){
//                 return {i,j};
//             }
//         }
//     }
// }

// // better(hashing)   SC-O(n)  TC-
// pair<int,int> twoSum(vector<int>& a,int k){
//     int n=a.size();
//     map<int,int> m; 
//     for (int i = 0; i <n; i++) {
//         if(m.find(k-a[i])!=m.end()){
//             return {m[k-a[i]],i};
//         }
//         m[a[i]]=i;
//     }
// }

// optimal    TC-O(nlogn+n)  SC-O(1)
pair<int,int> twoSum(vector<int>& a,int k){
    int n=a.size();
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    while(i<j){
        if(a[i]+a[j]>k){j--;}
        else if(a[i]+a[j]<k){i++;}
        else{
            return {i,j};
        }
    }
}


int main(){
    int k=14;
    vector<int> a={2,5,6,8,11};
    pair<int,int> ans=twoSum(a,k);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}