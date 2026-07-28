// we need to traverse the tree using bfs
// and find the leaf nodes

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
    queue<ll> q;
    q.push(1);
    vector<ll> vis(n + 1, 0);
    vector<ll> child(n + 1, 0);
    vis[1] = 1;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        ll c = 0;
        for (auto it : tree[node])
        {
            if (vis[it] == 0)
            {
                c += 1;
                vis[it] = 1;
                q.push(it);
            }
            else
            {
            }
        }
        child[node]=c;
    }
    cout<<"The leaf nodes are: "<<"\n";
    for(ll i=1;i<=n;i++) {
        if(child[i]==0)
            cout<<i<<" ";
    }
    cout<<"\n";
}