// //1Q) find the target from rotated sorted array (no duplicate elements)
// #include<bits/stdc++.h>
// using namespace std;

// int BS(vector<int> &a, int target, int n) {
//     int st=0,end=n-1;
//     while(st<=end){
//         int mid=st+(end-st)/2;
//         if(a[mid]==target){
//             return mid;
//         }else if(a[mid]>=a[st]){   //if left half is sorted
//             if(a[mid]>target && a[st]<=target){end=mid-1;}
//             else{st=mid+1;}
//         }else{ //if right half is sorted
//             if(a[mid]<target && a[end]>=target){st=mid+1;}
//             else{end=mid-1;}
//         }
//     }

//     return -1;
// }

// int main(){
//     vector<int> a = {6,7,8,0,1,2,3,4,5};
//     int target = 1;
//     int result = BS(a, target,a.size());
//     cout << "Element found at index: " << result << endl;

//     return 0;
// }


// // 2Q) find the target from rotated sorted array (with duplicate elements)
// #include<bits/stdc++.h>
// using namespace std;

// int BS(vector<int> &a, int target, int n) {
//     int st=0,end=n-1;
//     while(st<=end){
//         int mid=st+(end-st)/2;
//         if(a[mid]==target){
//             return mid;
//         }
//         if(a[mid]==a[st] && a[mid]==a[end]){ //if both ends are same, we cannot decide which half is sorted
//             // as a[mid]!=target, we can just remove one element from both ends
//             st++;
//             end--;
//             continue;
//         }else if(a[mid]>=a[st]){   //if left half is sorted
//             if(a[mid]>target && a[st]<=target){end=mid-1;}
//             else{st=mid+1;}
//         }else{ //if right half is sorted
//             if(a[mid]<target && a[end]>=target){st=mid+1;}
//             else{end=mid-1;}
//         }
//     }

//     return -1;
// }

// int main(){
//     vector<int> a = {6,7,8,0,1,2,3,4,5};
//     int target = 1;
//     int result = BS(a, target,a.size());
//     cout << "Element found at index: " << result << endl;

//     return 0;
// }

// 3Q)find the minimum element in rotated sorted array (with duplicate elements)
#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> &a, int n) {
    int ans=INT_MAX;
    int st=0,end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(a[mid]==a[st] && a[mid]==a[end]){ //if both ends are same, we cannot decide which half is sorted
            ans=min(ans,a[st]);
            st++;
            end--;
            continue;
        }else if(a[mid]>=a[st]){   //if right half is unsorted
            ans=min(ans,a[st]);
            st=mid+1;
        }else{ //if left half is unsorted
            ans=min(ans,a[mid]);
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> a = {6,7,8,0,1,2,3,4,5};
    int result = BS(a, a.size());
    cout << "Element found at index: " << result << endl;

    return 0;
}
