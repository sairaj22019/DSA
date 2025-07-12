// given integer x and n, find the nth root of x. if nth root is not an integer, return -1.


// 1)
// #include<bits/stdc++.h>
// using namespace std;

// // calculate x^n by exponentiation by multiplication  O(log n)
// int power(int x, int n){
//     int ans=1;
//     while(n>0){
//         if(n%2==1){ 
//             ans*=x;
//         }
//         else{
//             x*=x;
//             n/=2;  
//         }
//     }
//     return ans;
// }


// // O(log x * log n) time complexity
// int nth_root(int x, int n){
//     int low=1, high=x;
//     while(low<=high){
//         int mid=low+(high-low)/2;
//         if(power(mid,n)==x){
//             return mid;
//         }else if(power(mid,n)<x){
//             low=mid+1;
//         }else{high=mid-1;}
//     }
//     return -1;
// }

// int main(){
//     int x, n;
//     cin >> x >> n;
//     cout<<nth_root(x,n);
//     return 0;
// }

// the above solution is not efficient for large x and n, power(x,n) will overflow for higher x and n value.
// 2)
#include<bits/stdc++.h>
using namespace std;

int func(int mid,int n,int x){
    int ans=1;
    for(int i=0;i<n;i++){
        ans*=mid;
        if(ans>x) return -1; // if ans exceeds x, return -1
    }
    if(ans==x) return 1; // if ans equals x, return 1
    return 0; // if ans is less than x, return 0
}

int nth_root(int x, int n){
    int low=1, high=x;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(func(mid,n,x)==1){
            return mid;
        }else if(func(mid,n,x)==0){
            low=mid+1;
        }else{high=mid-1;}
    }
    return -1;
}

int main(){
    int x, n;
    cin >> x >> n;
    cout<<nth_root(x,n);
    return 0;
}
