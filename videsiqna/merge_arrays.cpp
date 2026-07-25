// to find the number of ways such that
// array a and array b
// after merging them their internal ordering should be intact
// the formula becomes
// (a+b)C(b) or (a+b)C(a)
// here a and b are the sizes of 2 arrays

// editorial- https://claude.ai/share/29346ec8-f5cd-4593-9bdc-50b1e8ebe8c2

#include <bits/stdc++.h>
using namespace std;
int fact(int n) {
    int f=1;
    for(int i=n;i>=1;i--)
        f*=i;
    return f;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int res=0;
    int num=fact(a+b);
    int den=fact(b)*fact((a+b)-b);
    res=num/den;
    cout<<"The number of ways are: "<<"\n";
    cout<<res<<"\n";
}