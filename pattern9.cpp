// to create
//   *
//  ***
// *****
//  ***
//   *

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        for (int j = 1; j <= (n / 2 + 1) - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    int cnt = n / 2;
    for (int i = 1; i <= (n / 2); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * cnt - 1; j++)
        {
            cout << "*";
        }
        cnt -= 1;
        cout << "\n";
    }
    return 0;
}