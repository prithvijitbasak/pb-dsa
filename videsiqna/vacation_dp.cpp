// q: https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    vector<ll> c(n + 1);
    for(ll i=1;i<=n;i++) {
        cin>>a[i]>>b[i]>>c[i];
    }
    

    // dp[i][j] will store the max happiness on day i if we do activity j
    // j = 1 (Activity A), j = 2 (Activity B), j = 3 (Activity C)
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
    
    // Base Case: On day 1, the max happiness for each activity is just its own value
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    
    // Fill the DP table for days 2 through n
    for(ll i = 2; i <= n; i++) {
        // If we choose A today, we must have chosen B or C yesterday
        dp[i][1] = a[i] + max(dp[i-1][2], dp[i-1][3]);
        
        // If we choose B today, we must have chosen A or C yesterday
        dp[i][2] = b[i] + max(dp[i-1][1], dp[i-1][3]);
        
        // If we choose C today, we must have chosen A or B yesterday
        dp[i][3] = c[i] + max(dp[i-1][1], dp[i-1][2]);
    }
    
    // The answer is the maximum value achievable on the final day across all 3 choices
    cout << max({dp[n][1], dp[n][2], dp[n][3]}) << "\n";
}