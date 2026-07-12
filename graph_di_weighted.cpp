// how to initialise a directed weighted graph
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[n+1];
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        // graph[v].push_back({u,w});
    }
    // Print adjacency list
    for(int i=1;i<=n;i++) {
        cout << i << " -> ";
        for(auto neighbor : graph[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << "\n";
    }
}