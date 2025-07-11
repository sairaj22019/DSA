#include <bits/stdc++.h>
using namespace std;

void print(map<int,string> &m){
    cout<<m.size()<<endl;
    for(auto &val:m){
        cout<<val.first<<" "<<val.second<<endl; // TC:O(log(n))
    }
    // the above loop TC:n*log(n)
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,string> m; // Keys of map are unique
    m[1] = "abc"; // insertion TC: O(log(n))
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4,"def"});
    // map<int,string> :: iterator it;
    // for(it= m.begin();it!=m.end();it++){
    //     cout<<(*it).first<<" "<<(*it).second<<endl; //or
    //     cout<<it->first<<" "<<it->second<<endl;
    // }

    print(m);


    auto it = m.find(3); //TC:O(log(n))
    if(it==m.end()){
        cout<<"The given value is not present"<<endl;
    }else{
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    m.erase(3);
    print(m);


    // Question 
    map<string , int> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    for(auto &val:mp){
        cout<<val.first<<" "<<val.second<<endl;
    }

    return 0;
}