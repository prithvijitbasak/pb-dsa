// given a graph
// we need to find the shortest distance to every node from ....
// node s
// https://www.hackerearth.com/problem/algorithm/shortest-distance-from-source/


#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,e;
    cin>>n>>e;
    vector<int> graph[n+1];
    for(int i=1;i<=e;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s;
    cin>>s;
    queue<int> q;
    vector<int> vis(n+1,0);
    vector<int> level(n+1,0);
    level[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: graph[node]) {
            if(!vis[it]) {
                level[it]=level[node]+1;
                vis[it]=1;
                q.push(it);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<level[i]<<" ";
    }
    cout<<"\n";
}