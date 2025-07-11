#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {1,2,3,4,5};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> ::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(int value : v){
        cout<<value<<" "; // value is just a copy , use & to change actual value
    }
    cout<<endl;
    for(int &value : v){
        value++;
    }
    for(int value:v){
        cout<<value<<" ";
    }
    cout<<endl;
    for(auto val:v){
        cout<<val<<" ";
    }
    cout<<endl;
    vector<pair<int,int>> v_p = {{1,2},{3,4}};
    for(pair<int,int> pair:v_p){
        cout<<pair.first<< " "<<pair.second<<endl;
    }
    for(auto &pair:v_p){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}