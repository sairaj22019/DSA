// ex: if arr1={1,1,2,3,4,5} ans arr2={2,3,4,4,5,6} ,union={1,2,3,4,5,6}

#include<bits/stdc++.h>
using namespace std;

// //brute force   time-O(n1logn + n2logn)+O(n1+n2)  space-O(n1+n2)+O(n1+n2)
// //here we are creating new array to store union vector, if we just had to print values we can directly print from set hence avoid new array ,then time-O(n1logn+n2logn)  space-O(n1+n2)
// vector<int> unionOfVectors(vector<int> a1,vector<int> a2){
//     int n1=a1.size();
//     int n2=a2.size();
//     set<int> s;
//     for (int i = 0; i <n1; i++) {
//         s.insert(a1[i]);
//     }
//     for (int i = 0; i <n2; i++) {
//         s.insert(a2[i]);
//     }
//     vector<int> temp;
//     for(auto val:s){
//         temp.push_back(val);
//     }
//     return temp;
// }

// optimised(2pointers)  time-O(n1+n2)  space-O(n1+n2)
// if we dont have to just print union we can directly print values with storing in new array, then time-O(n1+n2)  space-O(n1+n2);
vector<int> unionOfVectors(vector<int>& a1,vector<int>& a2){
    int n1=a1.size();
    int n2=a2.size();
    vector<int> temp;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            if(temp.empty()||a1[i]!=temp.back()){
                temp.push_back(a1[i]);
            }
            i++;
        }else{
            if( temp.empty()||a2[j]!=temp.back()){
                temp.push_back(a2[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if( a2[j]!=temp.back() || temp.empty()){
            temp.push_back(a2[j]);
        }
        j++;
    }
    while(i<n1){
        if( a1[i]!=temp.back() || temp.empty()){
            temp.push_back(a1[i]);
        }
        i++;
    }
    return temp;
}

int main(){
    vector<int> a1={1,1,2,3,4,5,8,8};
    vector<int> a2={2,3,4,4,5,6};
    vector<int> ans=unionOfVectors(a1,a2);
    for(auto val:ans){cout<<val<<" ";}
    return 0;
}