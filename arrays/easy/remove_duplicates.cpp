// give a sorted array.remove duplicates.
//i.e if in a array has as size of 10 and has3 unique element, replace first three indexes with unique value. later elements can be anything.
// also return size of unique value array.
//ex.   {1,1,1,2,2,2,2,2,3,3} ======> {1,2,3,2,2,2,2,2,3,3}

#include<bits/stdc++.h>
using namespace std;

// //brute force-  time-O(nlogn+n)    space-o(n)
// int removeDuplicates(vector<int>& a) {
//     int n=a.size();
//     set<int> s;
//     for (int i = 0; i <n; i++) {
//         s.insert(a[i]);
//     }
//     int ind=0;
//     for(int x:s){
//         a[ind]=x;
//         ind++;
//     }
//     return ind;
// }

//two pointers-   time-O(n)    space-O(1)
int removeDuplicates(vector<int>& a) {
    int n=a.size();
    int i=0,j=1;
    for (int j = 1; j <n; j++) {
        if(a[j]!=a[j-1]){
            a[i+1]=a[j];
            i++;
        }
    }
    return i+1;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i <n; i++) {
        cin>>a[i];
    }
    int size=removeDuplicates(a);
    for (int i = 0; i <size; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}