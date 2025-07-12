// given a sorted 2d array and number k , find the index of k.

#include<bits/stdc++.h>
using namespace std;

// brute   TC- O(n*m)
// traverse entire 2d array to find element

// // better   TC- O(nlogm)
// int binarySearch(vector<int>& nums, int k) {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == k) return mid;
//         else if (k > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1;
// }
// pair<int,int> search(vector<vector<int>>& a,int k){
//     int n=a.size(),m=a[0].size();
//     pair<int,int> ans = {-1,-1};
//     for (int i = 0; i < n; i++) {
//         if (a[i][0] <= k && k <= a[i][m - 1]) {
//             ans.first=i;
//             int ind=binarySearch(a[i], k);
//             if(ind!=-1){return {-1,-1};}
//             ans.second=ind;
//         }
//     }
//     return ans;
// }


// optimal  TC-O(log(n*m))
// lets hypothetically convert this 2d array into 1d array. the indexes of 1d array will go from 0 to n*m-1. so we can directly apply binery search on this single 1d array. 
pair<int,int> search(vector<vector<int>>& a,int k){ 
    int n = a.size();
    int m = a[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;  //converting 1d index into 2d index
        if (a[row][col] == k) {return {row,col};}
        else if (a[row][col] < k) {low = mid + 1;}
        else { high = mid - 1;}
    }
    return {-1,-1};

}

int main(){
     vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
     int k=7;
     pair<int,int> ind= search(a,k);
     cout<<ind.first<<" "<<ind.second;
    return 0;
}