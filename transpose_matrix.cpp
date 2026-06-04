// to do
// 1 2 3
// 4 5 6
// 7 8 9
// print :
// 1 4 7
// 2 5 8
// 3 6 9

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int mat[m][n];
    int res_mat[n][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res_mat[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << res_mat[i][j] << " ";
        }
        cout << "\n";
    }
}