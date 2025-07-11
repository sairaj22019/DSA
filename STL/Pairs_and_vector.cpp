#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int , string> p;
    // p = make_pair(2,"abc");
    p = {2,"abc"};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int , string> &p1 = p;
    p1.second = "sairaj";
    cout<<p.first<<" "<<p.second<<endl;
    int a[3] = {1,2,3};
    int b[3] = {2,3,4};

    pair<int,int> p_array[3];
    p_array[0]={1,2};
    p_array[1]={2,3};
    p_array[2]={3,4};
    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
    swap(p_array[0] , p_array[2]);
    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }

    return 0;
}