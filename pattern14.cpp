// to create
// 1357
// 3571
// 5713
// 7135

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int idx = 0;
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        if (i & 1)
        {
            arr[idx] = i;
            idx += 1;
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    int temp = n;
    idx = 0;
    for (int i = 1; i <= n; i++)
    {
        idx = i - 1;
        for (int j = 1; j <= n; j++)
        {
            if (idx >= n)
                idx = idx % n;
            cout << arr[idx];
            idx += 1;
        }
        cout << "\n";
    }
}