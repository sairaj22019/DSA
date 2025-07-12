// given array of increasing positive integers nad number k.find kth missing integer

#include<bits/stdc++.h>
using namespace std;

// // brute  -O(n)
// int KthMissing(vector<int>& a,int k){
//     int n=a.size();
//     // let assume are all starting k integers are missed and ans is k
//     for (int i = 0; i <n; i++) {
//         if(a[i]<k){k++;} // if a number appears before k, we increament the answer
//         else{return k;}
//     }
//     return k;
// }


// binery search  -O(logn)
int KthMissing(vector<int>& a,int k){
    int n=a.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=a[mid]-(mid+1); //formula for number of intergers misses before and index
        if(missing<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
        // at the end (high,low) is the intervel in which the required missing number exists
        // number of integers missed before a[high] is missed= a[high]-(high+1)
        // the number of intergers to be missed more = k-missed
        // so final integer is a[high]+more = k+high+1 or low+k (as at the end high+q is low)
        // if we do this calculation through code, it causes error when low ends at 0th index and high at -1 . therefore we have to calculate the final formula saperatly.
    return low+k;
}

int main(){
    vector<int> a = {2,3,4,7,11};
    int k = 5;
    cout<<KthMissing(a,k);
    return 0;
}