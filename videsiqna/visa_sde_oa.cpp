// Q: https://www.desiqna.in/16114/visa-oa-sde-intern-ctc-30-lac-27th-oct

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll lampsz;
    cin>>lampsz;
    vector<vector<ll>> lamps;
    for(ll i=0;i<lampsz;i++) {
        ll x,y;
        cin>>x>>y;
        lamps.push_back({x,y});
    }
    ll n;
    cin>>n;
    vector<ll> points(n);
    for(ll i=0;i<n;i++) {
        cin>>points[i];
    }
    // we are using here a efficient range update trick such that
    // from starting l we are adding 1 
    // and at r+1 we are adding -1
    // summation of all those will tell us how many numbers
    // are getting added at ith index 
    vector<ll> ans(1e5+10,0);
    for(ll i=0;i<lampsz;i++) {
        ll l=lamps[i][0];
        ll r=lamps[i][1];
        ans[l]+=1;
        ans[r+1]-=1;
    }
    for(ll i=1;i<1e5+10;i++)
        ans[i]+=ans[i-1];
    for(ll i=0;i<n;i++) {
        ll val=points[i];
        cout<<ans[val]<<" ";
    }
    cout<<"\n";
}