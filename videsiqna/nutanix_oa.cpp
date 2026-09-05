// we are given with 5 arrays a,b,c,d,e
// and we need to find such index 
// such that a[i]+b[j]+c[k]+d[l]+e[m]=0
// this is same  as 4 sum ii problem leetcode
// https://leetcode.com/problems/4sum-ii/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    vector<ll> d(n);
    vector<ll> e(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    for(ll i=0;i<n;i++) cin>>c[i];
    for(ll i=0;i<n;i++) cin>>d[i];
    for(ll i=0;i<n;i++) cin>>e[i];
    unordered_map<ll,ll> ump;
    for(auto it1:a) {
        for(auto it2:b) {
            ump[it1+it2]+=1;
        }
    }
    ll ans=0;
    for(auto it3:c) {
        for(auto it4:d) {
            for(auto it5:e) {
                ans+=ump[-(it3+it4+it5)];
            }
        }
    }
    cout<<ans<<"\n";
}