// height of each node in a tree

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(ll node, vector<ll> tree[],vector<ll> &vis, vector<ll> &parent, vector<ll> &height) {
    vis[node]=1;
    for(auto child: tree[node]) {
        if(vis[child]==0) {
            parent[child]=node;
            dfs(child,tree,vis,parent,height);
        }
    }
    ll h=0;
    for(auto child:tree[node]) {
        if(child==parent[node]) {
            // ignoring this portion
        }
        else {
           h=max(h,height[child]);
        }
    }
    height[node]=1+h;
}
int main() {
    ll n,e;
    cin>>n>>e;
    vector<ll> tree[n+1];
    for(ll i=1;i<=e;i++) {
        ll x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<ll> height(n+1,0);
    vector<ll> vis(n+1,0);
    // vis[1]=1;
    vector<ll> parent(n+1);
    dfs(1,tree,vis,parent, height);
    cout<<"The heights are: "<<"\n";
    for(ll i=1;i<=n;i++) {
        cout<<i<<" -> "<<height[i]<<"\n";
    }
}