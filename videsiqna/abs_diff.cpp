// to find such i,j where abs(a[i]-a[j]) == k and i<j

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
    cin>>k;
    unordered_map<int, int> ump;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // extremely neccessary point
        int need1 = k + arr[i];
        int need2 = arr[i]-k;
        if (ump.find(need1) != ump.end())
            ans += ump[need1];
        if (ump.find(need2) != ump.end())
            ans += ump[need2];
        ump[arr[i]] += 1; 
    }
    cout<<"The number of indices are: "<<ans<<"\n";
}
