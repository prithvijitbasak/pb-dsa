// we need to find the shortest path from starting node: 1
// to target node n
// such that the path should have maximum number of 5 in it
// its an undirected unweighted graph

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
                level[it] = level[node] + 1;
                if (value[it] == 5)
                    cnt_f[it] = cnt_f[node] + 1;
                else 
                    cnt_f[it]=cnt_f[node];
            }
            else
            {
                if (level[it] == level[node] + 1) {
                    int temp;
                    if(value[it]==5)
                        temp=cnt_f[node]+1;
                    else
                        temp=cnt_f[node];
                    cnt_f[it]=max(temp,cnt_f[it]);
                }
            }
        }
    }
    cout<<"Showing the distance and the 5's count"<<"\n";
    for(int i=1;i<=n;i++) {
        cout<<"Node "<<i<<" "<<level[i]<<" "<<cnt_f[i]<<"\n";
    }
    
}