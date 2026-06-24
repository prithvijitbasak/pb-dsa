// google OA
// we need to find the minimum sum of product of all a[i]*b[i]
// after arranging a and b in any order. 


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++)
        cout<<a[i]*b[i]<<" ";
    cout<<"\n";
}