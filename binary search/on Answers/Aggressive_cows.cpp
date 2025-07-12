// an array of positions of stalls and integer k(no. of cows) are given.
// allocates cows to stall and max possible value of min of distances between any 2 cows.

#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>&a, int dist , int k){
    int cnt=1 , prev=a[0];
    for (int i = 1; i <a.size(); i++) {
        if(a[i]-prev>=dist){
            cnt++;
            prev=a[i];
        }
    }
    if(cnt>=k){return true;}
    else{return false;}
}


// // brute- O((max-min)*n) 
// int ans(vector<int>&a,int k){
//     int n=a.size();
//     sort(a.begin(),a.end());
//     int ans=1;
//     for (int i = 1; i <=a[n-1]-a[0]; i++) {
//         if(possible(a,i,k)){continue;}
//         else{return i-1;}
//     }
// }



// binary search- O(nlog(max(a)-min(a))) 
int ans(vector<int>&a,int k){
    int n=a.size();
    sort(a.begin(),a.end());
    int low=0,high=a[n-1]-a[0];
    while(low<high){
        int mid=low+(high-low)/2;
        if(possible(a,mid,k)){
            low=mid+1;
        }else{high=mid-1;}
    }
    return high;
}

int main(){
    vector<int> a={0,3,4,7,10,9};
    int k=4;
    cout<<ans(a,k);
    return 0;
}