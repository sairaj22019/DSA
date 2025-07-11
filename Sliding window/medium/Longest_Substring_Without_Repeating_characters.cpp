#include <bits/stdc++.h>
using namespace std;

// brute force : Generate all the sub strings (TC : O(N*N) SC : O(N))
int solve(string &s){
    int n = s.length();
    int maxlen = INT_MIN;
    map<char,bool> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]=true;
        int currlen=1;
        for(int j=i+1;j<n;j++){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]=true;
                currlen++;
            }else break;
        }
        maxlen = max(maxlen,currlen);
        mp.clear();
    }
    return maxlen;
}

// optimal solution   TC:O(N*logN ) SC:O(N)  or if hash array is used then TC:O(N) SC:O(256)
int solve2(string &s){
    int l=0,r=0;
    map<char,int> mp;
    int currlen=0;
    int maxlen=0;
    while(r<s.length()){
        char ch = s[r];
        if(mp.find(ch)==mp.end()){
            currlen = r-l+1;
        }else{
            if(mp[ch]>=l){
                l=mp[ch]+1;
            }
            currlen=r-l+1;
        }
        mp[ch]=r;
        maxlen=max(maxlen,currlen);
        r++;
    }
    return maxlen;
        
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    cout<<solve2(s)<<endl;
    return 0;
}