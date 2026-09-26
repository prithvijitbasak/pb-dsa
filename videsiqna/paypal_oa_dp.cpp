// we are given a string of size n and we need to find
// the largest substring
// the condition is of substring is that
// no adjacent chars should have difference in ascii values greater than k

// though its a dp question we dont need

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    string s;
    cin >> s;
    ll n = s.size();
    ll k;
    cin >> k;
    // abcdefgh
    ll maxlen = 1;
    ll currstart = 0;
    ll mxstart = 0;
    ll minend = 0;
    ll len = 1;
    ll mxlen = 1;
    for (ll i = 1; i < n; i++)
    {
        if (abs(s[i] - s[i - 1]) <= k)
        {
            len += 1;
        }
        else
        {
            if (len > mxlen)
            {
                mxlen = len;
                mxstart = currstart;
            }
            currstart = i;
            len = 1;
        }
    }
    if (len > mxlen)
    {
        mxlen = len;
        mxstart = currstart;
    }
    cout << s.substr(mxstart, mxlen) << "\n";
}