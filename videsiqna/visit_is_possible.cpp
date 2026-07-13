// we need to find if we can visit each node from
// starting node 1 or not?
// using BFS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    int start = 1;
    // considering there are disconnected components also the question states that
    // the starting index is 1
    vis[start] = 1;
    queue<int> q;
    q.push(start);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    cout << "Checking if all the nodes are actually " << "\n";
    for (int i = 0; i <= n; i++)
    {
        cout<<i<<" is ";
        if(vis[i])
            cout<<"Yes";
        else
            cout<<"No";
        cout<<"\n";
    }
}