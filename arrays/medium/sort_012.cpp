//array only consists of 0,1,2. sort array

#include<bits/stdc++.h>
using namespace std;

// brute force
// use any sorting algorithm,like merge sort   TC-O(nlogn)   SC-O(n)

// better   TC-O(2n)  SC-O(1)
void sort012(vector<int>& a){
    int n=a.size();
    int zerocount=0,onecount=0,twocount=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){zerocount++;}
        else if(a[i]==1){onecount++;}
        else{twocount++;}
    }

    for(int i=0;i<zerocount;i++){a[i]=0;}
    for(int i=zerocount;i<zerocount+onecount;i++){a[i]=1;}
    for(int i=zerocount+onecount;i<n;i++){a[i]=2;}
}

// Dutch National Flag Algorithm   TC-O(n)  SC-O(1)
// refer strivers video
void sort012(vector<int>& a){
    int n=a.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[mid],a[low]);
            mid++;
            low++;
        }else if(a[mid]==1){
            mid++;
        }else{
            swap(a[mid],a[high]);
            high--;
        }
    }
    
}

int main(){
    vector<int> a={0,1,1,0,1,2,1,2,0,0,0};
    sort012(a);
    for(int x:a){cout<<x<<" ";}
    return 0;
}