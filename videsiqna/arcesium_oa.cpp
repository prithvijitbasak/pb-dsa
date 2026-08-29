// Q: https://www.desiqna.in/13736/arcesium-oa-sde1-jan-2023
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    
    string s1, s2;
    cin >> s1 >> s2;
    string new_s1 = "", new_s2 = "";
    if (s1.size() != s2.size()) {
        cout << "No\n";
        return 0; // End the program early since they can't be twins
    }
    ll n=s1.size();
    
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            new_s1 += s1[i];
            new_s2 += s2[i];
        }
    }
    ll ok = 1;
    sort(new_s1.begin(), new_s1.end());
    sort(new_s2.begin(), new_s2.end());
    if (new_s1 != new_s2)
        ok = 0;
    new_s1 = "", new_s2 = "";
    n=s2.size();
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            new_s1 += s1[i];
            new_s2 += s2[i];
        }
    }
    sort(new_s1.begin(), new_s1.end());
    sort(new_s2.begin(), new_s2.end());
    if (new_s1 != new_s2)
        ok = 0;
    
    if(ok) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}