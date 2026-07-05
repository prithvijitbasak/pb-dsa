// Link - https://codeforces.com/contest/1151/problem/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    ll a, b;
    ll ans = 0;
    // extremely crucial step as
    // ai⋅(j−1)+bi⋅(n−j) is required to find the answer
    // but this can also be written as
    // ai.j-bi.j + bi.n-ai (i and j are 1-based indexing so its very crucial)
    // this part ai.j-bi.j is variable but bi.n-ai this is a constant
    // so we only need to rearrange and find the way to minimise this part
    // ai.j-bi.j
    vector<ll> diff(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a >> b;
        ans += (b * n - a);
        diff[i]=(a-b);
    }
    sort(diff.rbegin(),diff.rend());
    for(int i=0;i<n;i++)
        ans+=(diff[i]*(i+1));
    
    cout << ans << "\n";
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
