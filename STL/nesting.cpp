// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     map<pair<string,string> , vector<int>> mp;
//     int n;
//     cin>>n;
//     while(n--){
//         string fn,ln;
//         int ct;
//         cin>>fn>>ln>>ct;
//         for(int i=0;i<ct;i++){
//              int x;
//              cin>>x;
//              mp[{fn,ln}].push_back(x);
//         }
//         for(auto &pr:mp){
//             cout<<pr.first.first<<" "<<pr.first.second<<" = { ";
//             for(auto &val:pr.second){
//                 cout<<val<<" ";
//             }
//             cout<<"}";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multimap<int,string> mp;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        int marks;
        cin>>s>>marks;
        mp.insert({marks,s});
    }
    cout<<endl;
    auto it = --mp.end();
    while(it!=mp.begin()){
        cout<<it->second<<" "<<it->first<<endl;
        it--;
    }
    cout<<it->second<<" "<<it->first<<endl;
    return 0;
}