// given an array in which each element appear twice except one,find that number

#include<bits/stdc++.h>
using namespace std;

// // brute force TC-O(n^2)  SC-O(1) 
// int singleElement(vector<int>& a){
//     int n =a.size();
//     for (int i = 0; i <n; i++) {
//         int num=a[i];
//         int cnt=0;
//         for (int j = 0; j <n; j++) {
//             if(a[i]==a[j]){cnt++;}
//         }
//         if(cnt==1){return num;}
//     }
// }


//better(hashing with array)
// traverse array to find max element
// create a hash array of length max+1
// traverse array and (hash[arr[i]]++;)  {storing frequencies of a[i] at a[i]th index of hash array}
// traverse hash array and find index with value 1   OR  traverse given array and check if (hash[a[i]]==1)
//therefore   TC=O(n+n+max_element) OR TC=O(n+n+n) 
//            SC-O(max_element)


// // but if numbera are negative or very large , above method fails
// // more optimal(hashing with map)
// // SC=O(n/2  +1)  as there are n/2+1 distinct elements
// // if we use map TC= O(Nlog(M)+M) {where M=number of elements in map=N/2 +1}
// // if we use unorder map TC=O(N+(N/2 +1))  but in very critical case TC=O(N^2 +(N/2 +1))
// int singleElement(vector<int>& a){
//     int n =a.size();
//     unordered_map<int,int> m;
//     for (int i = 0; i <n; i++) {
//         m[a[i]]++;
//     }
//     for(auto i:m){
//         if(i.second==1){return i.first;}
//     }
// }

// optimal  TC=O(N)  SC=O(1)
//as each element appears twice they get cancelled while taking xor and only element which appears once remain
int singleElement(vector<int>& a){
    int n =a.size();
    int xorr=0;
    for (int i = 0; i <n; i++) {
        xorr=xorr^a[i];
    }
    return xorr;
}
int main(){
    vector<int> a={1,3,4,2,4,1,2,8,8};
    cout<<singleElement(a);
    return 0;
}