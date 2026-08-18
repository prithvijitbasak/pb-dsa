// we are being given an array of n size 
// there are five unique integers we are given a,b,c,d,e
// these numbers are present in array multiple times and apart from these numbers
// there are other numbers as well
// we need to find the number of subarrays which have equal number of 
// a,b,c,d,e appearing
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    map<tuple<ll,ll,ll,ll>,ll> mp;
    mp[{0,0,0,0}]=1;
    ll ca=0,cb=0,cc=0,cd=0,ce=0;
    ll ans=0;
    for(ll i=1;i<=n;i++) {
        if(arr[i]==a) ca+=1;
        if(arr[i]==b) cb+=1;
        if(arr[i]==c) cc+=1;
        if(arr[i]==d) cd+=1;
        if(arr[i]==e) ce+=1;
        ll da=cb-ca;
        ll db=cc-cb;
        ll dc=cd-cc;
        ll dd=ce-cd;
        if(mp.find({da,db,dc,dd})!=mp.end())
            ans+=mp[{da,db,dc,dd}];
        mp[{da,db,dc,dd}]+=1;
    }
    cout<<"Number of such subarrays are: "<<ans<<"\n";
}