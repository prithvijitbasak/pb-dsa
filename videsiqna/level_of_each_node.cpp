// we need to find the level of each node in a graph
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
    vector<int> level(n + 1, -1);
    // considering there are no disconnected components and
    // starting node is 0
    int start = 1;
    level[start] = 0;
    queue<int> q;
    q.push(start);
    vector<int> vis(n + 1, 0);
    // vis[0]=1;
    vector<int> bfs;
    vis[start] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                level[it] = level[node] + 1;
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " -> Level " << level[i] << "\n";
    }
}
