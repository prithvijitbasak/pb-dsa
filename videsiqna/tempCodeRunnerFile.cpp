#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s,t;
    cin>>s>>t;
    unordered_map<char,ll> smap,tmap;
    for(auto it:s)
        smap[it]+=1;
    for(auto it:t)
        tmap[it]+=1;
    ll ans=INT_MAX;
    for(auto it:tmap) {
        if(smap.find(it.first)!=smap.end()) {
            ans=min(ans,smap[it.first]);
        }
        else {
            ans=0;
        }
    }
    cout<<ans<<"\n";
}