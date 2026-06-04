// to do
// take input matrix say m x n
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// print:
// 1 2 3 6 5 4 7 8 9

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
            cin >> mat[i][j];
    }
    int way = 1; // to print from left to right
    for (int i = 0; i < m; i++)
    {
        if (way)
        {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
        way = 1 - way;
    }
}
