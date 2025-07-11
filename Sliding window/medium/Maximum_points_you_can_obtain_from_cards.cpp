// find maximum sum of k elements choosen either from back or front or combined from back and front and they should be continous

#include <bits/stdc++.h>
using namespace std;


// TC:O(k+k) SC:O(1)
int solve(vector<int> &v , int k){
    int n = v.size();
    int f_sum=0,b_sum=0; // initialize front sum and back sum to 0
    for(int i=0;i<k;i++){ // calculate the sum of first k numbers
        f_sum+=v[i];
    }
    int ans = f_sum;
    for(int i=1;i<=k;i++){ // for each iteration remove one element from front and add one element from back   
        f_sum-=v[k-i];
        b_sum+=v[n-i];
        ans = max(ans, f_sum+b_sum);
    }
    return ans;


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
    cout<<solve(v,k)<<endl;

    return 0;
}