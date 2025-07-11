#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        multiset<long long> ms;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            ms.insert(x);
        }
        long long ans = 0;
        while(k--){
            ans += *(--ms.end());
            long long val = *(--ms.end())/2;
            ms.insert(val);
            auto it = ms.find(*(--ms.end()));
            if(it!=ms.end()){
                ms.erase(it);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}