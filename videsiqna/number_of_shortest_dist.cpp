// we need to find the number of shortest distances 
// from starting node 
// tutorial: https://claude.ai/chat/228a29f8-6240-40b2-85a2-712551990326 

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
    queue<int> q;
    q.push(1);
    vector<int> vis(n+1,0);
    vis[1]=1;
    vector<int> level(n+1,0);
    level[1]=0;
    vector<int> ways(n+1,0);
    ways[1]=1;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it:graph[node]) {
            if(!vis[it]) {
                vis[it]=1;
                q.push(it);
                ways[it]=ways[node];
                level[it]=level[node]+1;
            }
            else {
                if(level[it]==level[node]+1)
                    ways[it]=ways[it]+ways[node];
            }
        }
    }
    cout<<"The ways from start is: "<<"\n";
    for(auto it: ways)
        cout<<it<<" ";
}