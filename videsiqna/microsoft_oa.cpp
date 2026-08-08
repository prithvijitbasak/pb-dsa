// q: https://www.desiqna.in/13267/microsoft-coding-oa-sde-1-may-3-2023
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get_dig_sum(ll val)
{
    ll temp = val;
    ll sum = 0;
    while (temp)
    {
        ll rem = temp % 10;
        sum += rem;
        temp /= 10;
    }
    return sum;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    unordered_map<ll, pair<ll, ll>> ump;
    // for every digsum we are storing the 
    // largest and second largest elements which have digsum
    // into the map

    for (ll i = 1; i <= n; i++)
    {
        ll val = arr[i];
        ll digsum = get_dig_sum(val);
        // here if we found the same digsum then 
        // we are simply updating the largest and second largest sum
        if (ump.find(digsum) != ump.end())
        {
            ll lar = ump[digsum].first;
            ll seclar = ump[digsum].second;
            if (val >= lar)
            {
                ump[digsum].first = val;
                // this line is important because when we find new largest value
                // then the existing largest should become second largest.
                ump[digsum].second = lar;
            }
            else if (val < lar and val > seclar)
                ump[digsum].second = val;
        }
        else
        {

            ump[digsum].first = val;
        }
        // cout<<digsum<<" "<<ump[digsum].first<<" "<<ump[digsum].second<<"\n";
    }
    ll ans = INT_MIN;
    ll found_pair = 0;
    for (auto it : ump)
    {
        // if there are no any second largest value for any digsum
        // then it means that no any pairs could happen
        if (it.second.second > 0)
        {
            found_pair = 1;
            ll sum = it.second.first + it.second.second;
            ans = max(ans, sum);
        }
    }
    if (!found_pair)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}