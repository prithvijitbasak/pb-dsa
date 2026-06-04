#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        ump[x]+=1;
    }
    while(q--)
    {
        int x;
        cin>>x;
        cout<<ump[x];
        cout<<"\n";
    }
    cout<<"\n";
}