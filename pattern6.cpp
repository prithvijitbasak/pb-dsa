// to create
// A
// B C
// C D E
// D E F G

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        ch=ch+(i-1);
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch += 1;
        }
        
        cout << "\n";
    }
}