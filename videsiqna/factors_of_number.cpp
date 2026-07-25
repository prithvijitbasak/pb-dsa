// to find the factors of a number.
// we will only traverse till sqrt(n)
// where n is the input integer
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get_sqrt(ll n)
{
    ll prob_ans = -1;
    for (ll i = 1; (i * i) <= n; i++)
    {
        if (i * i <= n)
            prob_ans = i;
    }
    return prob_ans;
}
int main()
{
    ll n;
    cin >> n;
    ll half = get_sqrt(n);
    vector<ll> ans;
    for (ll i = 1; i <= half; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                ans.push_back(i);
            else
            {
                ans.push_back(i);
                ans.push_back(n / i);
            }
        }
    }
    cout << "The factors are: " << "\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
}