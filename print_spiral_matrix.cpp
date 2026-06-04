// to do
// input
// mxn matrix
// lets say m = 3
// n = 3
// matrix:
// 1 2 3
// 4 5 6
// 7 8 9
// to print:
// 1 2 3 6 9 8 7 4 5

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int mat[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top += 1;

        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right -= 1;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom -= 1;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left += 1;
        }
    }
}