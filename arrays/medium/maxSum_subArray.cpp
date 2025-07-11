// find max sum of elements of subarray

#include<bits/stdc++.h>
using namespace std;

// //brute force  TC-O(n^2)  SC-O(1)
// int majorityElement(vector<int>& a){
//     int n=a.size();
//     int ans=INT_MIN;
//     for (int i = 0; i <n; i++) {
//         int sum=0;
//         for (int j = i; j <n; j++) {
//             sum+=a[j];
//             ans=max(sum,ans);
//         }
//     }
//     return ans;
// }

//optimal(Kadane's algorithm)   TC-O(n)  SC-O(1)
int majorityElement(vector<int>& a){
    int n=a.size();
    int ans=INT_MIN;
    int sum=0;
    for (int i = 0; i <n; i++) {
        sum+=a[i];
        ans=max(ans,sum);
        if(sum<0){sum=0;}
    }
    if(ans<=0){return 0;}
    return ans;
}

int main(){
    vector<int> a={-2,-3,4,-1,-2,1,5,-3};
    int ans=majorityElement(a);
    cout<<ans<<endl;
    return 0;
}