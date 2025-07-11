// type : Longest sub array or sub string where <condition>


#include <bits/stdc++.h>
using namespace std;

// bruteforce : find all subarrays and figure out the max len subarray with sum less than or equal to k

//optimal 1 
int solve(vector<int> &v , int k){
    int n=v.size();
    int l=0,r=0; // initialize left and right pointers to 0
    int maxlen=0;
    int sum=0;
    while(r<n){
        sum+=v[r];
        if(sum<=k){
             maxlen = max(maxlen,r-l+1);
        }
        else {
            while(sum>k && l<=r) sum-=v[l++];
        }
        r++;
    }
    return maxlen;
}



// most optimized : ** only if we just need the max lenght not the elements **

int solve2(vector<int> &v , int k){
    int n=v.size();
    int l=0,r=0; // initialize left and right pointers to 0
    int maxlen=0;
    int sum=0;
    while(r<n){
        sum+=v[r];
        if(sum<=k){
             maxlen = max(maxlen,r-l+1);
        }
        else {
            if(sum>k && l<=r) sum-=v[l++]; // instead of while loop just if codition works because we already got the current max sum of certain length and our final answer will be atleast of our current max len so why to decrease the window size by using while loop
        }
        r++;
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
    cout<<solve2(v,k)<<endl;
    return 0;
}