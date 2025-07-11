#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    auto it = min_element(v.begin(),v.end());
    cout<<*it<<endl;
    auto it2 = max_element(v.begin(),v.end());
    cout<<*it2<<endl;
    int sum = accumulate(v.begin(),v.end(),0);
    cout<<sum<<endl;
    int cnt = count(v.begin(),v.end(),3);
    cout<<cnt<<endl;
    auto element = find(v.begin(),v.end(),2);
    cout<<*element<<endl;

    
    return 0;
}