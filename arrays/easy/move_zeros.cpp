//given an array, move all zeroes to the end
// ex: {1,2,0,3,0,0,4,5,2,0,3,0} ==> {1,2,3,4,5,2,3,0,0,0,0,0}

#include<bits/stdc++.h>
using namespace std;

// // time-O(2n)  space-O(n) {space complexity is O(x) where x is number of non-zero numbers, so in worst case it is }
// void movezeroes(vector<int>& a, int n){
//     vector<int> temp;
//     for (int i = 0; i <n; i++) {
//         if(a[i]!=0){
//             temp.push_back(a[i]);
//         }
//     }
//     for (int i = 0; i <temp.size(); i++) {
//         a[i]=temp[i];
//     }
//     for (int i = temp.size(); i <n; i++) {
//         a[i]=0;
//     }
// }

// optimisation(2 pointer)   time-O(n)  space-O(1)
void movezeroes(vector<int>& a, int n){
    int j=0;
    for (int i = 0; i <n; i++) {
        if(a[i]==0){
            j=i;
            break;
        }
    }
    for (int i = j+1; i <n; i++) {
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }

}

int main(){
    vector<int> a={1,2,0,3,0,0,4,5,2,0,3,0};
    movezeroes(a,a.size());
    for (int i = 0; i <a.size(); i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}