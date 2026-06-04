// to create
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// print = 1 2 3 4 7 10 13 14 15 16

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i-1][j-1];
        }
    }
    for (int i = 0; i < n; i++)
        cout << mat[0][i] << " ";
    for (int i = 1; i < n - 1; i++)
        cout << mat[i][n - 1 - i] << " ";
    for (int i = 0; i < n; i++)
        cout << mat[n - 1][i] << " ";
}