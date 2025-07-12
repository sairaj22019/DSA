// for given interger x, find the floor of square root of x
// ex: for 27, return 5 

#include<bits/stdc++.h>
using namespace std;

int sqrt(int x){
    // int low=1, high=x;
    // while(low<=high){
    //     int mid=low+(high-low)/2;
    //     if(x>=mid*mid && x<(mid+1)*(mid+1)){
    //         return mid;
    //     }else if(x>=(mid+1)*(mid+1)){
    //         low=mid+1;
    //     }else{high=mid-1;}
    // }
    // return -1;

    // OR

    int low=1, high=x;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid<=x){
            ans=mid;
            low=mid+1;
        }else{high=mid-1;}
    }
    return ans; //or return high;  //(at the end high will point to answer)
}

int main(){
    int x;
    cin >> x;
    cout<<sqrt(x);
    return 0;
}

