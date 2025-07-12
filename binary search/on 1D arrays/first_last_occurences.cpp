// given a sorted array, find the index of first occurrence and last occurrence of a given element

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 2;
    int lb = lower_bound(a.begin(), a.end(), target) - a.begin();
    int ub = upper_bound(a.begin(), a.end(), target) - a.begin();
    if(lb==a.size() || a[lb]!=target){ // we just have to check for one of lb or ub as if lb exists, ub will surely exist
        cout<<"Element not found"<<endl;
    } else {
        cout<<"First occurrence: "<<lb<<", Last occurrence: "<<ub-1<<endl;
    }
    return 0;
}