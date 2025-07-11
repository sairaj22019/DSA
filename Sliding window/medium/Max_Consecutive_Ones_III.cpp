// return maximum consectuive ones in an array of 0 and 1 , you are allowed to flip atmost k 0s to 1s

// the problem can also be written as largest subarray with max zeroes as k

#include <bits/stdc++.h>
using namespace std;

// Brute force : Generate all subarrays with atmost k zeroes and then figure out which has the max length
// TC:O(N*N) SC:O(1)
int solve(vector<int> &v , int n , int k){
    int maxlen=0;
    for(int i=0;i<n;i++){
        int cnt0=0,currlen=0;
        for(int j=i;j<n;j++){
            if(v[j]==0){
                if(cnt0<k) cnt0++;
                else break;
            }
            // currlen++; // this is also correct
            currlen = j-i+1;
        }
        maxlen=max(maxlen,currlen);
    }
    return maxlen;
}

// Optimal solution 1: Sliding window and two pointer TC:O(N+N)  SC:O(1)

int solve2(vector<int> &v , int n , int k){
    int maxlen=0,l=0,r=0,cnt0=0,currlen=0;
     while(r<n){
        if(v[r]==0) cnt0++;
        while(cnt0>k){ // at max it will run for N times overall 
            if(v[l]==0) cnt0--;

            l++;
        }
        currlen = r-l+1;
        maxlen = max(maxlen,currlen);
        r++;
     }
     return maxlen;
}


// Most Optimal solution: Trimming the inner while loop because even if you bring l such that the number of zeros doesnot exceed k then the length will be smaller than maxlen which we dont need 
// TC:O(N) SC:O(1) 
int solve3(vector<int> &v , int n , int k){
    int maxlen=0,l=0,r=0,cnt0=0,currlen=0;
     while(r<n){
        if(v[r]==0) cnt0++;
        if(cnt0>k){   
            if(v[l]==0) cnt0--;

            l++;
        }
        if(cnt0<=k){ // update only if the cnt0<=k
            currlen = r-l+1;
            maxlen = max(maxlen,currlen);
        }
        r++; // more right pointer everytime
     }
     return maxlen;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v,n,k)<<endl;
    cout<<solve2(v,n,k)<<endl;
    cout<<solve3(v,n,k)<<endl;


    return 0;
}