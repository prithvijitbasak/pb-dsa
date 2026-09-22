// we need to find the minimum cost to reach from 1 to n 
// pos of an array 
// conditions are : we can move from a[i] to a[i]+1 or a[i]+3
// cost = abs(a[i]-a[i+1]) / abs(a[i]-a[i+3])
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    vector<ll> dp(n+10,0);
    
    if(n>=2) dp[2]=dp[1]+abs(arr[1]-arr[2]);
    if(n>=3) dp[3]=dp[2]+abs(arr[2]-arr[3]);
    
    for(ll i=4;i<=n;i++) {
        dp[i]=min(dp[i-1]+abs(arr[i-1]-arr[i]),dp[i-3]+abs(arr[i-3]-arr[i]));
    }
    cout<<dp[n]<<"\n";
}