// https://www.desiqna.in/18853/microsoft-oa-stock-july-kumar-k
// micrososft OA
// we will be given composition[]
// we will be given stock[]
// we will be given prices[]
// budget

// we need to find how many alloys can we create (key point: we need every value of composition)
#include <bits/stdc++.h>
using namespace std;
bool valid(long long mid, vector<int> composition, vector<int> stock, vector<int> prices, int budget)
{
    int n = composition.size();
    long long totalCost = 0;
    for (int i = 0; i < n; i++)
    {
        long long need = mid * composition[i];
        long long extra = need - stock[i];
        if (extra < 0)
        {
            // this condition is to check
            // extra*prices[i]>budget if yes then no need to calculate further
            // else calculate
            // but if the extra*prices[i] is very high (greater than long long) then it may overflow
            // thats why this is checked like this
            if (extra > budget / prices[i])
                return false;
            totalCost += extra * prices[i];
            if (totalCost > budget)
                return false;
        }
    }
    return totalCost <= budget;
}
int main()
{
    int n;
    cin >> n;
    vector<int> composition(n);
    for (int i = 0; i < n; i++)
        cin >> composition[i];
    vector<int> stock(n);
    for (int i = 0; i < n; i++)
        cin >> stock[i];
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    int budget;
    cin >> budget;

    long long low = 1, high = 1e9;
    long long ans;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (valid(mid, composition, stock, prices, budget))
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    cout << ans << "\n";

    return 0;
}