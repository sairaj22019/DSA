#include<bits/stdc++.h>
using namespace std;

// Optimal
int count(vector<int>& a,int k){
    int n= a.size();
    map<int,int> presum;  // to store pre-sum of each element
    int sum=0;
    int cnt=0;
    presum[0]=1;
    for (int i = 0; i <n; i++) {
        sum+=a[i];
        int rem=sum-k;
        cnt+=presum[rem];
        presum[sum]++;
        
    }
    return cnt;
}


int main(){
    int k=3;
    vector<int> a={1,2,3,1,1,1,1,4,2,3};
    int ans=count(a,k);
    cout<<ans<<endl;
    return 0;
}