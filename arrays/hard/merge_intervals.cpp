// given an array of intervals. merge all the overlapping intervals


#include<bits/stdc++.h>
using namespace std;


// // brute time- O(nlogn + 2*n)  space-O(n)
vector<vector<int>> merge(vector<vector<int>>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;

}

// optimal   time- O(nlogn +n)    space-O(n)
vector<vector<int>> merge(vector<vector<int>>& a){
    int n=a.size();
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for (int i = 0; i <n; i++) {
        if(ans.size()>0 && a[i][0]<=ans.back()[1]){
            ans.back()[1]=max(ans.back()[1],a[i][1]);
        }else{
            ans.push_back(a[i]); // it is part of other sub interval the lowest value is greater than the greatest value of inside the answer
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> a={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans= merge(a);
    for(auto x:ans){
        cout<<"["<<x[0]<<","<<x[1]<<"]";
    }
    return 0;
}