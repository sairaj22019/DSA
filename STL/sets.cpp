// #include <bits/stdc++.h>
// using namespace std;

// void print(set<string> &s){
//     // for(auto it=s.begin();it!=s.end();it++){
//     //     cout<<*it<<" ";
//     // }
//     // cout<<endl;

//     // OR
//     for(auto &val: s){
//         cout<<val<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     set<string> s; // Inserting and accessing TC log(n)
//     s.insert("abc");
//     s.insert("xqw");
//     s.insert("abc");
//     s.insert("abd");
//     print(s);
//     auto it = s.find("abd"); // log(n)
//     if(it!=s.end()){
//         cout<<*it<<endl;
//     }
//     auto it2 = s.find("abd"); // log(n)
//     if(it2!=s.end()){
//         s.erase(it2);
//     }
//     s.erase("abc");
//     print(s);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        string s="";
        vector<int> mini(n),maxi(n);
        int sm = INT_MAX;
        int lg = INT_MIN;
        for(int i=0;i<n;i++){
            sm=min(sm,v[i]);
            mini[i]=sm;
        }
        for(int i=n-1;i>=0;i++){
            lg=max(lg,v[i]);
            maxi[i]=lg;
        }
        for(int i=0;i<n;i++){
            if(mini[i]>=v[i] || maxi[i]<=v[i]) s.push_back('1');
            else s.push_back('0');
        }
        cout<<s<<endl;

    }
    return 0;
}