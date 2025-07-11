#include <bits/stdc++.h>
using namespace std;

void print(multiset<string> &s){
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
    multiset<string> s;
    s.insert("abc");
    s.insert("xqw");
    s.insert("abc");
    s.insert("abd");
    print(s);

    auto it = s.find("abc"); // O(logn)
    if(it!=s.end()){
        s.erase(it); // only 1st occourance will be deleted
    }
    s.erase("abc"); // all occourances will be deleted
    return 0;
}