// count all pairs i,j of arr such that arr[i]-arr[j] == k
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    unordered_map<int, vector<int>> ump;
    int ans = 0;
    vector<pair<int, int>> idx;
    for (int i = 0; i < n; i++)
    {
        int need = k + arr[i];
        if (ump.find(need) != ump.end())
        {
            for (auto it : ump[need])
            {
                ans += 1;
                idx.push_back({it, i});
            }
        }
        ump[arr[i]].push_back(i);
    }
    if (ans != 0)
    {
        cout << "The count of indices are: " << ans << "\n";
        cout << "The indices are: " << "\n";
        for (auto it : idx)
            cout << it.first << " " << it.second << "\n";
    }
    else
    {
        cout << "There are no such indices" << "\n";
    }
}