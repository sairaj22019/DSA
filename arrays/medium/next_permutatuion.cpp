// find the next permutation(according to ascending order) of given array.if given array is last permutation,give first permutation

#include<bits/stdc++.h>
using namespace std;
// brute force
//find all permutations(by recursions) and arrange them in sorted order
//do linear search an find the given array from all permutations
//return the next permutation(permutation at next index) 

// better
void NextPermutation(vector<int>& a){
    next_permutation(a.begin(),a.end());
}

// opitmal  TC-O(3n)  SC-O(1)
// 1) traverse from back and find pivot which is the first number that decrease(a[i]<a[i+1])
// 2) again travese from back and find first number which is just greater that pivot, and swap them
// 3)arrange remaining in sorted order
void NextPermutation(vector<int>& a){
    int n=a.size();
    int pivot=-1;

    for (int i = n-2; i >=0; i--) {
        if(a[i]<a[i+1]){
            pivot=i;
            break;
        }
    }

    if(pivot==-1){//i.e array is in decresing order, so it is last permutation
    //so we return first permutation which the array in ascending order
        reverse(a.begin(),a.end()); 
        return;
    }
    for (int i = n-1; i >pivot; i--) {
        if(a[i]>a[pivot]){
            swap(a[i],a[pivot]);
            break;
        }
    }

    // we have to arrange remaining array in ascending order.
    reverse(a.begin()+pivot+1,a.end());//the remaining array is still in decreasing order so we just have to reverse

}


int main(){
    vector<int> a={2,1,5,4,3,0,0};
    NextPermutation(a);
    for(auto x:a){
        cout<<x<<" ";
    }
    return 0;
}



