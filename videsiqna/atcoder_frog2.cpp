// Q: https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findMin(vector<ll> &arr, ll k, ll idx,vector<ll> &dp) {
    ll minVal=INT_MAX;
    for(ll i=1;i<=k and (idx-i)>=1;i++) {
        minVal=min(minVal,dp[idx-i]+abs(arr[idx]-arr[idx-i]));
    }
    return minVal;
}
int main()
{
    ll n;
    cin >> n;
    ll k;
    cin>>k;
    vector<ll> arr(n+1,0);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    vector<ll> dp(n+1,0);
    
    dp[2]=abs(arr[1]-arr[2]);
    for(ll i=3;i<=n;i++) {
        
        ll minK=findMin(arr,k,i,dp);
        dp[i]=minK;
    }


    cout<<dp[n]<<"\n";
}