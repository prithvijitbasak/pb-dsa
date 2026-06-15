// microsoft OA
// two players are playing a game
// for a given array take the first element of the array and then add to their score
// if the element is even then reverse the array and if the elemet is odd then
// take that number and add to the score

// optimised solution
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = 0, right = n - 1;
    int fs = 1;
    int score1 = 0, score2 = 0;
    int rev = 0;
    int lastelem = 0;
    while (left <= right)
    {
        if (fs)
            score1 += !rev ? arr[left] : arr[right];
        else
            score2 += !rev ? arr[left] : arr[right];
        lastelem = !rev ? arr[left] : arr[right];
        !rev ? left += 1 : right -= 1;
        fs = 1 - fs;
        if (lastelem % 2 == 0)
            rev = 1 - rev;
    }
    cout << "The difference between the scores are: " << score1 - score2 << "\n";
}

// brute force approach
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     int iffirst = 1, ifsec = 0;
//     int fs = 0, ss = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] & 1)
//         {
//             if (iffirst and !ifsec)
//             {
//                 fs += arr[i];
//                 iffirst = 0;
//                 ifsec = 1;
//             }
//             else
//             {
//                 ss += arr[i];
//                 iffirst = 1;
//                 ifsec = 0;
//             }
//         }
//         else
//         {
//              if (iffirst and !ifsec)
//             {
//                 fs += arr[i];
//                 iffirst = 0;
//                 ifsec = 1;
//             }
//             else
//             {
//                 ss += arr[i];
//                 iffirst = 1;
//                 ifsec = 0;
//             }
//             reverse(arr.begin() + i + 1, arr.end());
//         }
//     }
//     cout<<fs-ss<<"\n";
// }