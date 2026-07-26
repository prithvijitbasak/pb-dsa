// ->Given two arrays A and B->find the number of
// valid pairs(A[i], B[j]) such that B[j] is multiple of A[i]

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 10), b(n + 10);
    unordered_map<ll,ll> umpA,umpB;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        umpA[a[i]]+=1;
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
        umpB[b[i]]+=1;
    }
    ll ans =0;
    for(auto it:umpA) {
        ll curr=it.first;
        ll cnt=0;
        for(ll j=curr;j<=1000006;j+=curr) {
            cnt+=umpB[j];
        }
        ans+=cnt*umpA[curr];
    }
    cout<<"The number of pairs can be: "<<"\n";
    cout<<ans<<"\n";
}
