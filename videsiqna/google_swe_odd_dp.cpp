// Find the number of journeys where you start
// from index 1 and end at index ‘n’ and the sum of every journey should be odd..
// Allowed to make jumps of size 1 or 2
// same for even as well

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<ll>> dp(n + 10, vector<ll>(3, 0));
    // 1 for odd
    // 2 for even
    if (n >= 1)
    {
        dp[1][2] = (arr[1] % 2 == 0) ? 1 : 0;
        dp[1][1] = (arr[1] % 2 != 0) ? 1 : 0;
    }

    if (n >= 2)
    {
        if (arr[2] % 2 == 0)
        {
            // Adding an even number keeps the parity the same
            dp[2][1] = dp[1][1];
            dp[2][2] = dp[1][2];
        }
        else
        {
            // Adding an odd number flips the parity
            dp[2][1] = dp[1][2]; // even sum + odd element = odd sum
            dp[2][2] = dp[1][1]; // odd sum + odd element = even sum
        }
    }

    for (ll i = 3; i <= n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            // Even element: Parity remains the same as the previous steps
            dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
            dp[i][2] = dp[i - 1][2] + dp[i - 2][2];
        }
        else
        {
            // Odd element: Parity flips (Odd comes from Even, Even comes from Odd)
            dp[i][1] = dp[i - 1][2] + dp[i - 2][2];
            dp[i][2] = dp[i - 1][1] + dp[i - 2][1];
        }
    }

    cout << "Odd ways: " << dp[n][1] << "\n";
    cout << "Even ways: " << dp[n][2] << "\n";
}
