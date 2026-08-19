// we are being given an array of n size 
// there are five unique integers we are given a,b,c,d,e
// these numbers are present in array multiple times and apart from these numbers
// there are other numbers as well
// we need to find the number of subarrays which have equal number of 
// a,b,c,d,e appearing
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
  Example trace based on "image_84f8c4.png":
  Assume targets are a=1, b=2, c=3, d=4, e=5
  Array values over iterations (1-indexed): [1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 1]

  i  | val | ca,cb,cc,cd,ce      | tuple (da,db,dc,dd) | mp[tuple] before      | ans += | ans after
  -------------------------------------------------------------------------------------------------
  1  | 1   | 1,0,0,0,0           | (-1,0,0,0)          | 0                     | 0      | 0
  2  | 2   | 1,1,0,0,0           | (0,-1,0,0)          | 0                     | 0      | 0
  3  | 3   | 1,1,1,0,0           | (0,0,-1,0)          | 0                     | 0      | 0
  4  | 4   | 1,1,1,1,0           | (0,0,0,-1)          | 0                     | 0      | 0
  5  | 5   | 1,1,1,1,1           | (0,0,0,0)           | 1 (seed)              | +1     | 1
  6  | 1   | 2,1,1,1,1           | (-1,0,0,0)          | 1 (i=1)               | +1     | 2
  7  | 2   | 2,2,1,1,1           | (0,-1,0,0)          | 1 (i=2)               | +1     | 3
  8  | 3   | 2,2,2,1,1           | (0,0,-1,0)          | 1 (i=3)               | +1     | 4
  9  | 4   | 2,2,2,2,1           | (0,0,0,-1)          | 1 (i=4)               | +1     | 5
  10 | 5   | 2,2,2,2,2           | (0,0,0,0)           | 2 (seed, i=5)         | +2     | 7
  11 | 9   | 2,2,2,2,2 (unchanged) | (0,0,0,0)         | 3 (seed, i=5, i=10)   | +3     | 10
  12 | 1   | 3,2,2,2,2           | (-1,0,0,0)          | 2 (i=1, i=6)          | +2     | 12
*/

int main() {
    ll n;
    cin >> n;

    // a, b, c, d, e are the 5 distinct target values we care about
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    vector<ll> arr(n + 1);  // 1-indexed array
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    // Map from a 4D "difference tuple" -> how many prefixes produced that tuple.
    // Two prefixes with the SAME tuple => the subarray between them has
    // equal counts of a, b, c, d, e (see derivation below).
    map<tuple<ll, ll, ll, ll>, ll> mp;

    // Seed: the "empty prefix" (before index 1) has all counts 0,
    // so its difference tuple is (0,0,0,0). This lets subarrays that
    // start at index 1 be counted correctly.
    mp[{0, 0, 0, 0}] = 1;

    // Running counts of each of the 5 target values, from array start to current index
    ll ca = 0, cb = 0, cc = 0, cd = 0, ce = 0;
    ll ans = 0;

    for (ll i = 1; i <= n; i++) {
        // Update only the counter matching the current value.
        // Values that aren't a/b/c/d/e are simply ignored (no counter changes),
        // so they can sit inside a valid subarray without affecting validity.
        if (arr[i] == a) ca += 1;
        if (arr[i] == b) cb += 1;
        if (arr[i] == c) cc += 1;
        if (arr[i] == d) cd += 1;
        if (arr[i] == e) ce += 1;

        // Compute the 4 "chained" differences between consecutive counts.
        // If count(a)=count(b)=count(c)=count(d)=count(e) over some subarray,
        // then ALL of these differences must be 0 for that subarray.
        // Tracking these 4 differences is like a 4D generalization of the
        // classic 1D prefix-sum trick (0s/1s equal-count subarray problem).
        ll da = cb - ca;  // count(b) - count(a)
        ll db = cc - cb;  // count(c) - count(b)
        ll dc = cd - cc;  // count(d) - count(c)
        ll dd = ce - cd;  // count(e) - count(d)

        // If this exact tuple (da,db,dc,dd) was seen at some earlier prefix index j,
        // then for the subarray (j, i]:
        //   da(i) - da(j) = 0  =>  Δcount(b) = Δcount(a)
        //   db(i) - db(j) = 0  =>  Δcount(c) = Δcount(b)
        //   dc(i) - dc(j) = 0  =>  Δcount(d) = Δcount(c)
        //   dd(i) - dd(j) = 0  =>  Δcount(e) = Δcount(d)
        // Chaining these: Δcount(a) = Δcount(b) = Δcount(c) = Δcount(d) = Δcount(e)
        // i.e., the subarray (j, i] has equal occurrences of a, b, c, d, e.
        // Every earlier prefix with this same tuple contributes one such valid subarray.
        if (mp.find({da, db, dc, dd}) != mp.end())
            ans += mp[{da, db, dc, dd}];

        // Record that the current prefix produced this tuple, so future
        // indices can match against it too.
        mp[{da, db, dc, dd}] += 1;
    }

    cout << "Number of such subarrays are: " << ans << "\n";
}