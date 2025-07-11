//for a given array.find the element which occurs more than [n/2] times.
#include<bits/stdc++.h>
using namespace std;

// // brute force   TC-O(n^2)   SC-O(1)
int majorityElement(vector<int>& a){
    int n=a.size();
    for (int i=0;i< n;i++) {
        int count=0;
        for(int j=0;j< n;j++){
            if(a[i]==a[j]){count++;}
        }
        if(count>n/2){return a[i];}
    }
    return -1;
}

// // better(hashing)  TC-O(nlogn + n){for map}    SC-O(n)
int majorityElement(vector<int>& a){
    int n=a.size();
    map<int,int> freq;
    for (int i = 0; i <n; i++) {
        freq[a[i]]++;
    }
    for(auto val:freq){
        if(val.second>n/2){return val.first;}
    }
    return -1;
}

// moore's vooting algorithm 
// refer strivers video 
int majorityElement(vector<int>& a){
    int n=a.size();
    int cnt=0;
    int el;
    for (int i = 0; i <n; i++) {
        if(cnt==0){
            el=a[i];
            cnt=1;
        }
        else if(a[i]==el){cnt++;}
        else{cnt--;}
    }
    // after above loop we got the element which has has chance to be majority
    // if there exists a majority element then it must be the element obtained from the above iteration

    // to verify whether el is majority or not
    int cnt_el=0;
    for (int i = 0; i <n; i++) {
        if(a[i]==el){cnt_el++;}
        if(cnt_el>n/2){return el;}
    }
    return -1;
}



int main(){
    vector<int> a={1,2,1};
    // vector<int> a={1,4,2,4,4,5,7,3,4,4,8,4,4};
    int ans=majorityElement(a);
    cout<<ans<<endl;
    return 0;
}