// given array of positions(int) of gas stations ,you have to place k station(float or int) and minimise the max distance between any 2 adjecent gas stations. the answer should match with accuracy of 6 digits after decimal point

#include<bits/stdc++.h>
using namespace std;

// // brute    TC- O(n*k+n)  SC-(n-1)
// float smallestMaxDist(vector<int>& a,int k){
//     int n=a.size();
//     vector<int> howMany(n-1,0);// stores how many gas stations are placed between i and i+1;
//     while(k--){ // to place k gas stations , each in each iteration
//         long double maxlength=-1; int maxInd=-1;
//         for (int i = 0; i <n-1; i++) {
//             long double diff=a[i+1]-a[i];
//             long double length= diff/(long double)(howMany[i]+1);
//             if(length>maxlength){
//                 maxlength=length;
//                 maxInd=i;
//             }
//         }
//         howMany[maxInd]++;

//     }
//     long double maxlength=-1;
//     for (int i = 0; i <n-1; i++) {
//         long double diff=a[i+1]-a[i];
//         long double length= diff/(long double)(howMany[i]+1);
//         maxlength=max(maxlength,length);
//     }
//     return maxlength;
// }


// // better    TC- O(nlogn+klogn)  SC-O(2*(n-1))
// float smallestMaxDist(vector<int>& a,int k){
//     int n=a.size();
//     vector<int> howMany(n-1,0);// stores how many gas stations are placed between i and i+1;
//     priority_queue<pair<long double,int>> pq;
//     for (int i = 0; i <n-1; i++) {
//         pq.push({a[i+1]-a[i],i}); //storing length and indexes
//     }

//     while(k--){ // to place k gas stations , each in each iteration
//         auto tp=pq.top();
//         pq.pop();
//         int ind=tp.second;
//         howMany[ind]++;
//         long double diff=a[ind+1]-a[ind];
//         long double newlength=diff/(long double)(howMany[ind]+1);
//         pq.push({newlength,ind});

//     }
    
//     return pq.top().first;
// }



// optimal    TC- O(n+nlogn)  SC-O(1)
int numberofGasStationsRequired(vector<int> a,long double dist){
    int cnt=0;
    for (int i = 1; i <a.size(); i++) {
        int numberInBetween=(a[i]-a[i-1])/dist;
        if((a[i]-a[i-1])/dist==numberInBetween*dist){
            numberInBetween--;
        }
        cnt+=numberInBetween;
    }
    return cnt;
}

float smallestMaxDist(vector<int>& a,int k){
    int n=a.size();
    long double low=0,high=0;
    for (int i = 0; i <n; i++) {
        high=max(high,(long double)(a[i+1]-a[i]));
    }
    while(high-low<1e-6){
        long double mid = (low+high)/(2.0);
        int cnt= numberofGasStationsRequired(a,mid);
        if(cnt>k){low=mid;}
        else{high=mid;}
    }
    return high; // here opposite polairty does not work
}

int main(){
    vector<int> a={1,2,3,4,5};
    int k=4;
    cout<<smallestMaxDist(a,k);
    return 0;
}