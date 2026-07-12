// Q: https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+1,0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> dp(n+1,0);
    dp[2]=abs(arr[1]-arr[2]);
    if(n>2)
        dp[3]=min(dp[1]+abs(arr[3]-arr[1]),dp[2]+abs(arr[3]-arr[2]));
    // if(n>3)
    //     dp[4]=min(dp[2]+abs(arr[4]-arr[2]),dp[3]+abs(arr[4]-arr[3]));
    for(int i=3;i<=n;i++) {
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout<<dp[n]<<"\n";
}