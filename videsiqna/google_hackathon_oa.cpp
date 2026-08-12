// Q: https://www.desiqna.in/13650/google-girl-hackathon-coding-questions-solutions-2023-kumar
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(100001);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    vector<ll> pre(n+k+100001,0);
    // for taking the queries (here there are no queries so it will be upto n)
    ll maxr=0;
    for(ll i=1;i<=n;i++) {
        // we are just thinking about the range from which the 
        // ith number can lie 
        // that is from -k to +k
        // its same as range_updating_trick
        ll l=arr[i]-k;
        ll r=arr[i]+k;
        pre[l]=pre[l]+1;
        pre[r+1]=pre[r+1]-1;
        maxr=max(maxr,r+1);
    }
    // atleast 1 element is possible
    ll ans=max(1LL, pre[0]);
    // now 
    for(ll i=1;i<=maxr;i++) {
        pre[i]+=pre[i-1];
        ans=max(pre[i],ans);
    }
    cout<<"The maximum number of equal elements that can happen: "<<ans<<"\n";
}
int main() {
    ll t;
    cin>>t;
    while(t--) solve();
}