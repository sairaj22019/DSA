// refer 3sum on leet code for question statement

#include<bits/stdc++.h>
using namespace std;

// brute force approach - TC: O(n^3*log(no. of triplets)) SC: 2*O(no. of triplets)
vector<vector<int>> three_sum(vector<int> &a, int n) {
    set<vector<int>> ans;
    for (int i = 0; i <n; i++) {
        for (int j = i + 1; j <n; j++) {
            for (int k = j + 1; k <n; k++) {
                if(a[i]+a[j]+a[k]==0){
                    vector<int> triplet = {a[i], a[j], a[k]};
                    sort(triplet.begin(), triplet.end());
                    ans.insert(triplet);
                }
            }
        }
    }
    vector<vector<int>> ans_vec(ans.begin(), ans.end());
    return ans_vec;
}

// better approach using hashing - TC: O(n^2*log(no. of triplets)) SC: O(2*no. of triplets+n)
vector<vector<int>> three_sum(vector<int> &a, int n) {
    set<vector<int>> ans;
    unordered_set<int> s;
    for (int i = 0; i <n; i++) {
        for (int j = i + 1; j <n; j++) {
            if(s.find(-1*(a[i]+a[j]))!=s.end()){
                vector<int> triplet = {a[i], a[j], -1*(a[i]+a[j])};
                sort(triplet.begin(), triplet.end());
                ans.insert(triplet);
            }
            s.insert(a[j]);
        }
        s.clear();
    }
    vector<vector<int>> ans_vec(ans.begin(), ans.end());
    return ans_vec;
}


// optimized approach - TC: O(n^2) SC: O(no. of triplets)
vector<vector<int>> three_sum(vector<int> &a, int n) {
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i <n; i++) {
        if(i>0 && a[i]==a[i-1]) continue;

        int left=i+1,right=n-1;
        while(left<right){
            if(a[left]+a[right]<-1*a[i]){left++;}
            else if(a[left]+a[right]>-1*a[i]){right--;}
            else{
                ans.push_back({a[i],a[left],a[right]});
                while(left<right && a[left]==a[left+1]){
                    left++;
                }
                left++;
                while(left<right && a[right]==a[right-1]){
                    right--;
                }
                right--;
            }
        }
        
    }
    return ans;
}



int main(){
    vector<int> a={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=three_sum(a,a.size());
    for(auto triplet:ans){
        for(int x:triplet){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}