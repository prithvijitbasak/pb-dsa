// to find the good pairs of penguins
// q: https://www.desiqna.in/18756/goldman-sachs-oa-2025-set-3-dancing-penguins
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin>>n;
    vector<ll> p1m,p2m,p1f,p2f;
    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x;
        if(x<0)
            p1m.push_back(abs(x));
        else
            p2m.push_back(x);
    }
    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x;
        if(x<0)
            p1f.push_back(abs(x));
        else
            p2f.push_back(x);
    }
    ll ans=0;
    ll i=0,j=0;
    if(p1m.size()>0)
        sort(p1m.begin(),p1m.end());
    if(p2m.size()>0)
        sort(p2m.begin(),p2m.end());
    if(p1f.size()>0)
        sort(p1f.begin(),p1f.end());
    if(p2f.size()>0)
        sort(p2f.begin(),p2f.end());
    while(i<p1m.size() and j<p2f.size()) {
        if(p1m[i]>p2f[j])
        {
            i+=1;
            j+=1;
            ans+=1;
        }
        else
        // this is very cruciual line because we would pair with those female penguins whose
        // height is smaller than male ones
        // so we are incrementing the male ones as moving right on male array
        // will ensure that we can get a higher male height with respect to the female. 
            i+=1;
    }
    i=0;
    j=0;
    while(i<p2m.size() and j<p1f.size())
    {
        if(p2m[i]<p1f[j]) {
            i+=1;
            j+=1;
            ans+=1;
        }
        else
        // same here as well.
            i+=1;
    }
    cout<<ans<<"\n";
}
