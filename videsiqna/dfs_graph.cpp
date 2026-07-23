// DFS on graph
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> graph[], vector<int> &vis, vector<int> &dfsList)
{
    vis[node] = 1;
    dfsList.push_back(node);
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            dfs(it, graph, vis, dfsList);
        }
    }
}
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
    vector<int> dfsList;
    vector<int> vis(n + 1, 0);
    int start = 1;
    vis[start] = 1;
    dfs(start, graph, vis, dfsList);
    cout << "The DFS is: " << "\n";
    for (auto it : dfsList)
        cout << it << " ";
    cout << "\n";
}