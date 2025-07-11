//for a given array. find number of subarrays whose xor is k.

#include<bits/stdc++.h>
using namespace std;

// // brute force- O(n^3)
// int subarraysWithXorK(vector<int> &a, int k) {
//     int n = a.size();
//     int count = 0;

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             int xorSum = 0;
//             for (int m = i; m <= j; m++) {
//                 xorSum ^= a[m];
//             }
//             if (xorSum == k) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// // better- O(n^2)
// int subarraysWithXorK(vector<int> &a, int k) {
//     int n = a.size();
//     int count = 0;

//     for (int i = 0; i < n; i++) {
//         int xorSum = 0;
//         for (int j = i; j < n; j++) {
//             xorSum ^= a[j];
//             if (xorSum == k) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// optimal- O(n)
int subarraysWithXorK(vector<int> &a, int k) {
    int n = a.size();
    int count = 0;
    unordered_map<int,int> m;
    int xr=0;
    m[0]++;
    for (int i = 0; i < n; i++) {
       xr=xr^a[i];
       count+=m[xr^k];       
       m[xr]++;
    }
    return count;
}




int main(){
    vector<int> a={4,2,2,6,4};
    int k=6;
    cout << subarraysWithXorK(a, k) << endl;
    return 0;
}