//Find second largest element of array

//1) brute force- O(nlogn+n)
// sort array. a[n-1] is largest.for second lagest traverse from n-2 to 0 and find first element which is not equal to largest

// //2) better approach- O(2n)
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for (int i = 0; i <n; i++) {
//         cin>>a[i];
//     }
//     int largest=a[0];
//     for (int i = 0; i <n; i++) {
//         if(a[i]>largest){largest=a[i];}
//     }
//     int slargest=-1;
//     for (int i = 0; i <n; i++) {
//         if(a[i]>slargest && a[i]!=largest){slargest=a[i];}
//     }
//     cout<<slargest<<endl;
//     return 0;
// }


//optimised-O(n)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i <n; i++) {
        cin>>a[i];
    }
    int largest=a[0],slargest=-1;
    for (int i = 1; i <n; i++) {
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];
        }else if(a[i]>slargest && a[i]!=largest){slargest=a[i];};
    }
    
    cout<<slargest<<endl;
    return 0;
}