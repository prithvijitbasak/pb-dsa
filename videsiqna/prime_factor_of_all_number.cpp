// we need to find the prime factor of all the number
// in array
// TC: O(n*20)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> spf(1e6 + 10);
void countSPF()
{
    for (ll i = 2; i <= 1e6; i++)
        spf[i] = i;
    for (ll i = 2; i * i <= 1e6; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j <= 1e6; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
int main()
{
    countSPF();
    ll n;
    cin >> n;
    vector<ll> arr(n + 10);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    cout<<"The prime factors of each index values are: "<<"\n";
    for (int i = 1; i <= n; i++)
    {
        cout<<"For index: "<<i<<" :"<<"\n";
        unordered_map<ll, ll> ump;
        ll num = arr[i];
        while (num != 1)
        {
            ll spfVal = spf[num];
            ump[spfVal] += 1;
            num /= spfVal;
        }
        for(auto it:ump)
            cout<<it.first<<" "<<it.second<<"\n";
    }
}