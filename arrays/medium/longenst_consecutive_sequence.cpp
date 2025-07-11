// for a give array, retrun length of longest sequence in which all numbers are consecutuive
// any numbers from array array and in any order can form sequence
#include<bits/stdc++.h>
using namespace std;

// // brute force  TC-O(N^2)  SC-O(1)
// // for every integer check whether there is next integer in array and increase count
// bool find(vector<int>& a,int x){
//     for (int i = 0; i <n; i++) {
//         if(a[i]==x){
//             return true;
//         }
//         return false;
//     }
// }
// int longest_sequence(vector<int>& a){
//     int n=a.size();
//     int longest=1;
//     for (int i = 0; i <n; i++) {
//         int num=a[i];
//         int cnt=1;
//         while(find(a,num+1)){
//             cnt++;
//             num+=1;
//         }
//         longest=max(longest,cnt);
//     }
// }

// better TC-O(nlogn+n)  SC-O(1)
// int longest_sequence(vector<int>& a){
//     int n=a.size();
//     int longest=1,cnt=1;
//     sort(a.begin(),a.end());
//     for (int i = 1; i <n; i++) {
//         if(a[i-1]+1==a[i]){
//             cnt++;
//         }
//         else if(a[i+1]!=a[i]){
//             cnt=1;
//         }
//         longest=max(longest,cnt);
//     }
//     return longest;
// }

// optimal  TC-O(n+2n)  SC-O(n)
int longest_sequence(vector<int>& a){
    int n=a.size();
    int longest=1;
    unordered_set<int> s;
    for (int i = 0; i <n; i++) {
        s.insert(a[i]);
    }
    for(int x:s){
        if(s.find(x-1)==s.end()){
            int cnt=1;
            int num=x;
            while(s.find(num+1)!=s.end()){
                num+=1;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }

    return longest;
}

int main(){
    vector<int> a={5,3,4,1,6,4,3,2,5};
    int ans=longest_sequence(a);
    cout<<ans<<endl;
    return 0;
}