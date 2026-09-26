// we are given an array and we can make 
// jumps or 1,3,5
// we need to find the maximum sum when we get to nth index

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n+10);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    vector<ll> dp(n+10,0);
    if(n>=1) dp[1]=arr[1];
    if(n>=2) dp[2]=dp[1]+arr[2];
    if(n>=3) dp[3]=dp[2]+arr[3];
    if(n>=4) dp[4]=max(dp[1]+arr[4],dp[3]+arr[4]);
    if(n>=5) dp[5]=max(dp[2]+arr[5],dp[4]+arr[5]);
    if(n>=6) dp[6]=max({dp[1]+arr[6],dp[3]+arr[6],dp[5]+arr[6]});
    for(ll i=7;i<=n;i++) {
        dp[i]=max({dp[i-5]+arr[i],dp[i-3]+arr[i],dp[i-1]+arr[i]});
    }
    cout<<dp[n]<<"\n";
}