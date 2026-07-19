// Your task is to find for each node ‘i’ ;
// find the number of the shortest paths from node - 1 to node i
// which also having maximum number of 5 possible in those paths

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> value(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> value[i];
    vector<int> graph[n + 1];
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // this is a array to store the level/distance with their count of 5's in it
    vector<int> level(n + 5, 0);
    vector<int> vis(n + 5, 0);
    level[1] = 0;
    vis[1] = 1;
    vector<int> cnt_f(n + 5, 0);
    queue<int> q;
    q.push(1);
    if (value[1] == 5)
        cnt_f[1] = 1;
    vector<int> ways(n + 1, 0);
    ways[1] = 1;
    vector<int> best5(n + 1, -1);
    best5[1] = (value[5] == 5) ? 1 : 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
                ways[it] = ways[node];
                level[it] = level[node] + 1;
                best5[it] = best5[node] + (value[it] == 5 ? 1 : 0);
            }
            else
            {
                if (level[it] == level[node] + 1)
                {
                    int cand = best5[node] + (value[it] == 5 ? 1 : 0);
                    // it means the path is strictly better path
                    if (cand > best5[it])
                    {
                        best5[it] = cand;
                        ways[it] = ways[node];
                    }
                    else if (cand == best5[it]) // if there are equal number of 5's then add those ways
                    {
                        ways[it] += ways[node];
                    }
                }
            }
        }
    }
    cout << "Showing the number of shortest distance and the 5's count" << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (level[i] == -1)
            cout << "Node " << i << " unreachable\n";
        else
            cout << "Node " << i << " dist=" << level[i]
                 << " max5=" << best5[i]
                 << " numPaths=" << ways[i] << "\n";
    }
}