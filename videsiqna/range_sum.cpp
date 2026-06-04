// to find the range of sum using prefix sum
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> freq = arr;
    for (int i = 1; i < n; i++)
        freq[i] = freq[i - 1] + arr[i];
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans;
        if (l == 0)
            ans = freq[r];
        else
            ans = freq[r] - freq[l - 1];
        cout << ans << "\n";
    }
}