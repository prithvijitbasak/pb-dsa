// how to initialise a undirected graph
// TC: O(v+e)
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // Print adjacency list
    for(int i=1;i<=n;i++) {
        cout << i << " -> ";
        for(int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}