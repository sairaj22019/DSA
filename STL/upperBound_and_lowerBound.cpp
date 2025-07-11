#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // sort(a,a+n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    
    // auto it1 = lower_bound(a,a+n,6);
    // auto it2 = upper_bound(a,a+n,6);
    // cout<<*it1<<endl;
    // cout<<*it2<<endl;

    // vector<int> v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // sort(v.begin(),v.end());
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // auto it = upper_bound(v.begin(),v.end(),4);
    // if(it == v.end()){
    //     cout<<"Not Found"<<endl;
    // }else{
    //     cout<<*it<<endl;
    // }



    /// for sets 

    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    int num;
    cin>>num;
    auto it = s.lower_bound(num); // if same values are present then iterator will point to the first occouring value
    if(it==s.end()){
        cout<<"Not found"<<endl;
    }else{
        cout<<*it<<endl;
    }
    return 0;
}