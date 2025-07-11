// given an array(all are positives(>=0)) and number k. find length of longest subarray whose sum is k

#include<bits/stdc++.h>
using namespace std;

// brute force  TC=O(n^2)  sc=O(1)
int longestSubarray(vector<int>& a,int k){
    int n= a.size();
    int ans=-1;
    for (int i = 0; i <n; i++) {
        int sum=0;
        for (int j = i; j <n; j++) {
            sum+=a[j];
            if(sum==k){ans=max(ans,j-i+1);}
            if(sum>k){break;}
        }
    }
    return ans;
}

// better(hashing)  TC-O(nlogn{map} or n{unoredered map} or n^2{worst case in unoderered map})
//                  SC-O(n)
int longestSubarray(vector<int>& a,int k){
    int n= a.size();
    map<int,int> presum;  // to store pre-sum of each element
    int sum=0;
    int maxlen=-1;
    for (int i = 0; i <n; i++) {
        sum+=a[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        int rem=sum-k;
        if(presum.find(rem)!=presum.end()){  // checking if any element has presum sum-k,if there then the subarray between both elements has sum=k 
            int len=i-presum[rem];
            maxlen=max(len,maxlen);
        }
        if(presum.find(sum)==presum.end()){ //checking if presum is already available,example if an element is 0 the index for presum is again changed which decreases size of subarray
            presum[sum]=i;
        }
    }
    return maxlen;
}

// optimal TC-O(2n)  SC-O(1)
int longestSubarray(vector<int>& a,int k){
    int n= a.size();
    int sum=a[0];
    int maxlen=-1;
    int i=0,j=0;
    while(i<n && j<n){
        if(sum>k){
            sum-=a[i];
            i++;
        }else if(sum<k){
            j++;
            if(j<n){sum+=a[j];}
        }else{
            maxlen=max(maxlen,j-i+1);
            j++;
            if(j<n){sum+=a[j];}
        }
    }
    return maxlen;
}

int main(){
    int k=3;
    vector<int> a={1,2,3,1,1,1,1,4,2,3};
    int ans=longestSubarray(a,k);
    cout<<ans<<endl;
    return 0;
}