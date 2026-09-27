// we need to find the minimum cost to reach nth index from 1st index
// we can go from ith index to jth index with at most a size of jump less than or equal to k
// k will be in input
// the cost of jump from i to j is arr[i]*arr[j]
// k will be greater than 0

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >>n;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    ll k;
    cin>>k;
    vector<ll> dp(n+10,INT_MAX);
    dp[1]=0;
    for(ll i=2;i<=n;i++) {
        for(ll j=max(1LL,i-k);j<i;j++) {
            dp[i]=min({dp[i],dp[j]+arr[j]*arr[i]});
        }
    }
    cout<<dp[n]<<"\n";
    
}