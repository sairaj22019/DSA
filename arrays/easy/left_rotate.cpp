//given an array.rotate array by d places
//ex: {1,2,3,4,5,6}   d=2 ===> {3,4,5,6,1,2}

#include<bits/stdc++.h>
using namespace std;

// // brute force  time- O(n+d)   space-O(d)
// void leftRotate(vector<int>& a,int n,int d){
//     d=d%n; // if d is greater than n
//     vector<int> temp(d);
//     for (int i = 0; i <d; i++) {
//         temp[i]=a[i];
//     }
//     for (int i = d; i <n; i++) {
//         a[i-d]=a[i];
//     }
//     for (int i = n-d; i <n; i++) {
//         a[i]=temp[i-(n-d)];
//     }
// }
    
// //optimised   time-O(2n)   space-O(1)
// void leftRotate(vector<int>& a,int n,int d){
//     reverse(a.begin(),a.begin()+d);
//     reverse(a.begin()+d,a.end());
//     reverse(a.begin(),a.end());
// }

void leftRotate(vector<int>& a,int n,int d){
    vector<int> temp(n);
    for (int i = 0; i <n; i++) {
        temp[i] = a[(i+d)%n];
    }
    a=temp;
}


int main(){
    vector<int> a={1,2,3,4,5,6,7};
    int d=3;
    leftRotate(a,a.size(),d);
    for(auto x: a){
        cout<<x<<" ";
    }
    return 0;
}