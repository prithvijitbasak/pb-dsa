// Q: https://www.desiqna.in/16114/visa-oa-sde-intern-ctc-30-lac-27th-oct
// what if there are -ve points aand the range of l and r could be upto
// 1e9
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll lampsz;
    cin >> lampsz;

    // Arrays to store the start (left) and end (right) points of the lamps independently
    vector<ll> left(lampsz);
    vector<ll> right(lampsz);

    /*
     * THE CORE MATHEMATICAL INTUITION:
     * A point P is illuminated by a lamp covering segment [L, R] if:
     * L <= P  AND  R >= P
     *
     * Instead of checking intervals one by one, we use set theory:
     * Active Lamps = (Lamps that started at or before P) - (Lamps that ended strictly before P)
     *
     * Mathematically:
     * Active Lamps = (Count of L <= P) - (Count of R < P)
     */

    // Read lamp intervals
    for (ll i = 0; i < lampsz; i++)
    {
        ll x, y;
        cin >> x >> y;
        left[i] = x;
        right[i] = y;
    }

    // Sort left and right endpoints independently to enable binary search.
    // Time complexity for sorting: O(N log N)
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll m;
    cin >> m;
    vector<ll> points(m);

    // Read query points
    for (ll i = 0; i < m; i++)
    {
        cin >> points[i];
    }

    vector<ll> ans;
    ans.reserve(m); // Reserve space to avoid reallocation overhead

    // Process each query point
    // Time complexity per query: O(log N) -> Total for M queries: O(M log N)
    for (ll i = 0; i < m; i++)
    {
        ll val = points[i];

        /*
         * WHY upper_bound FOR START?
         * We need the count of lamps that started AT OR BEFORE 'val' (L <= val).
         * upper_bound finds the first element STRICTLY GREATER than 'val' (> val).
         * Because the array is sorted, the index represents the count of all elements <= val.
         *
         * EXAMPLE: left = [1, 3, 5, 5, 8], val = 5
         * upper_bound(5) points to 8 (at index 4).
         * Index 4 means exactly 4 lamps (1, 3, 5, 5) started at or before 5.
         */
        ll start = upper_bound(left.begin(), left.end(), val) - left.begin();

        /*
         * WHY lower_bound FOR END?
         * We need the count of lamps that ended STRICTLY BEFORE 'val' (R < val).
         * lower_bound finds the first element GREATER THAN OR EQUAL to 'val' (>= val).
         * Because the array is sorted, the index represents the count of all elements < val.
         *
         * EXAMPLE: right = [2, 4, 5, 5, 9], val = 5
         * lower_bound(5) points to the first 5 (at index 2).
         * Index 2 means exactly 2 lamps (2, 4) ended strictly before 5.
         */
        ll endbefore = lower_bound(right.begin(), right.end(), val) - right.begin();

        // Active Lamps = (Lamps started at or before P) - (Lamps ended strictly before P)
        // From example above: 4 started - 2 ended = 2 active lamps at point 5.
        ans.push_back(start - endbefore);
    }

    // Output the results
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}