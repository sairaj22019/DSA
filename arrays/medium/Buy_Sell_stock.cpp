// given array contains cost of a stock at ith day.find max profit

#include<bits/stdc++.h>
using namespace std;

// brute force TC-o(n^2)
// take all possible

// optimal TC-O(n)
int stocks(vector<int>& a){
    int n=a.size();
    int min=a[0];
    int ibuy=0,isell=0;
    int maxprofit=0;
    while(isell<n){
        maxprofit=max( maxprofit,a[isell]-min);
        if(a[isell]<min){min=a[isell];}
        isell++;
    }
    return maxprofit;
}

int main(){
    vector<int> a={7,1,5,3,6,4};
    int ans=stocks(a);
    cout<<ans<<endl;
    return 0;
}