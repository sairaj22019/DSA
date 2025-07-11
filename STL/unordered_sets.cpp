#include <bits/stdc++.h>
using namespace std;

void print(unordered_set<string> &s){
    // for(auto it=s.begin();it!=s.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    // OR
    for(auto &val: s){
        cout<<val<<" ";
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<string> s; // insertion and finding TC O(1)
    s.insert("abc");
    s.insert("xqw");
    s.insert("abc");
    s.insert("abd");
    print(s);

    auto it = s.find("abd"); // O(1)
    if(it!=s.end()){
        cout<<*it<<endl;
    }
    return 0;
}