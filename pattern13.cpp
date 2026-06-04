// to create
//  * * * * *
//   *     *
//    *   *
//     * *
//      *

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            if (i == 1 or i == n or j == 1 or j == i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}