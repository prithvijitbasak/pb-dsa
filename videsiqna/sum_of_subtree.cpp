// we need to find the sum of all subtrees
// when the entire tree is rooted at 1

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(ll node, vector<ll> tree[], vector<ll> &val, vector<ll> &vis, vector<ll> &parent, vector<ll> &sum) {
    vis[node]=1;
    for(auto child:tree[node]) {
        if(vis[child]==0) {
            parent[child]=node;
            dfs(child, tree, val, vis, parent, sum);
        }
    }
    ll s=0;
    for(auto child: tree[node]) {
        if(child==parent[node]) {
            // ignoring
        }
        else {
            s+=sum[child];
        }
    }
    sum[node]=val[node]+s;
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
    vector<ll> val(n+1);
    for(ll i=1;i<=n;i++) cin>>val[i];
    vector<ll> vis(n+1,0);
    vector<ll> parent(n+1);
    vector<ll> sum(n+1,0);
    dfs(1, tree, val, vis, parent, sum);
    cout<<"The subtree sum of each node is: "<<"\n";
    for(ll i=1;i<=n;i++) 
        cout<<i<<" -> "<<sum[i]<<"\n";
}