// Given a Tree of ‘N’ Nodes and ‘N-1’ Edges; rooted at Node-1 ;
// each node is assigned either 1 or 0 ; for each node “i” ;
// find the number of 1’s on the shortest path from node 1 to node “i”
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> tree[n + 1];
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<ll> val(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> val[i];
    vector<ll> vis(n + 1, 0);
    vis[1] = 1;
    queue<ll> q;
    q.push(1);
    vector<ll> ans(n + 1);
    ans[1] = val[1] == 1 ? 1 : 0;
    while (!q.empty())
    {
        ll top = q.front();
        q.pop();
        ll c = 0;
        for (auto child : tree[top])
        {
            if (vis[child] == 0)
            {
                vis[child] = 1;
                q.push(child);
                c += 1;
                if (val[child] == 1)
                    ans[child] = ans[top] + 1;
                else
                    ans[child] = ans[top];
            }
            else
            {
            }
        }
    }
    cout << "The count of 1's till ith index is: " << "\n";
    for (ll i = 1; i <= n; i++)
        cout << i << " -> " << ans[i] << "\n";
    cout << "\n";
}