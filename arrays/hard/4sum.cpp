// refer 4sum question on leet code for question statement.   (similar to 3sum)

#include<bits/stdc++.h>
using namespace std;

// // brute force approach - TC: O(n^4*log(no. of quadruplets)) SC: 2*O(no. of quadruplets)
vector<vector<int>> four_sum(vector<int> &a, int target, int n) {
    set<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long sum = a[i]+a[j];
                    sum+=a[k];
                    sum+=a[l];
                    if (sum == target) {
                        vector<int> quadruplet = {a[i], a[j], a[k], a[l]};
                        sort(quadruplet.begin(), quadruplet.end());
                        ans.insert(quadruplet);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans_vec(ans.begin(), ans.end());
    return ans_vec;
}

// // better approach - TC: O(n^3*log(no. of quadruplets)) SC: 2*O(no. of quadruplets)+O(n)
vector<vector<int>> four_sum(vector<int> &a, int target, int n) {
    set<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<int> s;
            for (int k = j + 1; k < n; k++) {
                long long sum=a[i]+a[j];
                sum+=a[k]; // we add one by one to prevent overflow
                long long fourth=target-(sum);
                if(s.find(fourth)!=s.end()){
                    vector<int> temp = {a[i], a[j], a[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                s.insert(a[k]);
            }
        }
    }
    vector<vector<int>> ans_vec(ans.begin(), ans.end());
    return ans_vec;
}


// optimal - TC: O(nlogn+n^3) SC: O(no. of quadruplets) [no extra space is used, only 1 vector to return answer]
vector<vector<int>> four_sum(vector<int> &a, int target, int n) {
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if(i!=0 && a[i-1]==a[i]){continue;}

        for (int j = i + 1; j < n; j++) {
            if(j!=i+1 && a[j-1]==a[j]){continue;}
        
            int low=j+1,high=n-1;
            while(low<high){
                long long sum=a[i];
                sum+=a[j]; 
                sum+=a[low]; 
                sum+=a[high];
                if(sum== target){
                    vector<int> temp={a[i],a[j],a[low],a[high]};
                    ans.push_back(temp);
                    low++;
                    high--;
                    while(low<high && a[low]==a[low-1]){low++;}
                    while(low<high && a[high]==a[high+1]){high--;}
                }else if(sum<target){low++;}
                else{high--;} 
            }
        }
    }
    return ans;
}



int main(){
    vector<int> a = {1, 0, -1, 0, -2, 2};
    int target = 0; 
    vector<vector<int>> ans = four_sum(a, target, a.size());
    for(auto quad:ans){
        for(int x:quad){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}