// Q: https://leetcode.com/discuss/post/3114099/amazon-oa-intern-2024-by-anonymous_user-57od/
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
    // for each character present in target variable should be there 
    // should be atleast target_variable number of frequencies available
    // in source variable 
    // for 
    // s -> mononom 
    // t-> moon
    // then there is 1 possible way to make "moon" from "mononom"
    for(auto it:tmap) {
        if(smap.find(it.first)!=smap.end()) {
            ans=min(ans,smap[it.first]/it.second);
        }
        else {
            ans=0;
        }
    }
    cout<<ans<<"\n";
}