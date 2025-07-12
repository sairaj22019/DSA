// //1Q) for given sorted array, find lower bound i.e the least index at a[i] >= target


// // there is an inbuilt function lower_bound in C++ STL which does the same thing
// // lower_bound(a.begin(), a.end(), target) returns an iterator to the first element that is not less than target
// // so ans=lower_bound(a.begin(), a.end(), target) - a.begin();   this gives the index of the first element that is not less than target
// #include<bits/stdc++.h>
// using namespace std;

// int lower_bound(vector<int> &a, int target,int n) {
//     int left = 0;
//     int right = n-1;
//     int ans=n;
//     while (left < right) {
//         int mid = left + (right - left) / 2;
//         if (a[mid] < target) {
//             left = mid + 1;
//         } else {
//             ans= mid;
//             right = mid-1; 
//         }
//     }
//     return ans;
// }

// int main(){
//     vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int target = 5;

//     int index = lower_bound(a, target,a.size());
//     cout<<index<<endl;

//     return 0;
// }




//2Q) for given sorted array, find upper bound i.e the least index at a[i] > target


// there is an inbuilt function upper_bound in C++ STL which does the same thing
// upper_bound(a.begin(), a.end(), target) returns an iterator to the first element that is greater than target
// so ans=upper_bound(a.begin(), a.end(), target) - a.begin();   this gives the index of the first element that is greater than target
#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector<int> &a, int target,int n) {
    int left = 0;
    int right = n-1;
    int ans=n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= target) {
            left = mid + 1;
        } else {
            ans= mid;
            right = mid-1; 
        }
    }
    return ans;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;

    int index = upper_bound(a, target,a.size());
    cout<<index<<endl;

    return 0;
}


// 3Q) Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// A) just the return lower bound

// 4Q)