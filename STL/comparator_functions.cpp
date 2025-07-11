#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a , pair<int,int> b){
    if(a.second!=b.second){
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    cout<<"ans"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}