#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int,string> &m){
    cout<<m.size()<<endl;
    for(auto &val:m){
        cout<<val.first<<" "<<val.second<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int,string> m;
    m[1] = "abc"; // TC:O(1)
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4,"def"});
    print(m);

    auto it = m.find(3); //TC:O(1)
    if(it==m.end()){
        cout<<"The given value is not present"<<endl;
    }else{
        cout<<it->first<<" "<<it->second<<endl;
    }
    m.erase(3); // O(1)


    //Question
    unordered_map<string , int> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        cout<<mp[s]<<endl;
    }
    return 0;
}