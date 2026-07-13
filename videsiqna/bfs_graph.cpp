// BFS on Graph
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    vector<int> bfs;
    for (int start = 0; start <= n; start += 1)
    {
        if(vis[start])
            continue;
        queue<int> q;
        q.push(start);
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
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    cout << "The BFS is: " << "\n";
    for (auto it : bfs)
    {
        cout << it << " ";
    }
    cout << "\n";
}