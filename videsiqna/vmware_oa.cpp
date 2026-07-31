// vmware OA
// https://www.desiqna.in/12818/vmware-sde1-coding-questions-and-solutions-india-april-2023

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(ll node, vector<ll> &vis, vector<ll> &parent, vector<ll> tree[], vector<ll> &sum, vector<ll> &val)
{
    vis[node] = 1;
    for (auto child : tree[node])
    {
        if (vis[child]==0)
        {
            parent[child] = node;
            dfs(child, vis, parent, tree, sum, val);
        }
    }
    ll s = 0;
    for (auto child : tree[node])
    {
        if (child == parent[node])
        {
            // ignore
        }
        else
        {
            s = max(s, sum[child]);
        }
    }
    sum[node] = val[node] + s;
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<ll> tree[n + 1];
    for (ll i = 1; i <= e; i++)
    {
        ll x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<ll> val(n + 1);
    for (ll i = 0; i < n; i++)
        cin >> val[i];
    vector<ll> parent(n + 1);
    vector<ll> vis(n + 1, 0);
    vector<ll> sum(n + 1, INT_MIN);
    dfs(0, vis, parent, tree, sum, val);

    ll ans = *max_element(sum.begin(), sum.end());
    cout << "The maximum path sum is: " << ans << "\n";
}