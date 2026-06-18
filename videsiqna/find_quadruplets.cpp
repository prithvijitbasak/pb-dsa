// google OA
// for a sorted array need to find such quadruplets
// i, j, k, l where i>j>k>l
// arr[i]+arr[j]>k1 and arr[k]+arr[l]>k2
// and k1 and k2 will be given

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k1, k2;
    cin >> k1 >> k2;
    // O(n^2) solution
    //  we are just caring about the jth index and from
    //  0 to i-1 is the index of i and j and from
    //  j+1 to n-1 is the k and l
    int ans = 0;
    for (int j = 1; j <= n - 3; j++)
    {
        int i = j - 1;
        int c1 = 0, c2 = 0;
        while (i >= 0)
        {
            if (arr[i] + arr[j] > k1)
                c1 += 1;
            i -= 1;
        }
        // now for j+1 to n-1 for k and l
        int k = j + 1;
        int l = n - 1;
        while (k < l)
        {
            if (arr[l] + arr[k] > k2)
            {
                c2 += (l - k);
                l -= 1;
            }
            else
                k += 1;
        }
        ans += (c1 * c2);
    }
    cout << "Total number of quadruplets are: " << ans << "\n";
}
