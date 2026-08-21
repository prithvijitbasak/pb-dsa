// Q: https://www.desiqna.in/13820/google-oa-sde2-jan-2023


// we need to find such pairs in array 
// where i<j and arr[arr[arr[i]]]==arr[arr[arr[j]]]
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    // ll ans=0;
    unordered_map<ll,ll> ump;
    ll ans=0;
    for(ll i=1;i<=n;i++) {
        ll rhs=arr[arr[arr[i]]];
        ll g=ump[rhs];
        ans+=g;
        ll lhs=arr[arr[arr[i]]];
        ump[lhs]+=1;

    }

    
    cout<<ans<<"\n";
}