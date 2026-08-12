// suppose we are given an array with length n and all 0s
// and there will be q queries where in each query we will be given l and r
// and in that range I need to add 1 on every element
// after q queries we need to show the result array
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n+5,0);
    
    vector<ll> pre=arr;
    while(q--) {
        ll l,r;
        cin>>l>>r;
        // we will only add 1 to l index and 1 to r+1 index which would 
        // on summation from 1 to n we will get the resultant array 
        // because when we add 1 to l then the addition starts from l to r 
        // and after r+1 to n it gets subtracted as we added -1 to r+1
        pre[l]+=1;
        pre[r+1]-=1;
    }
    for(ll i=2;i<=n;i++)
    pre[i]+=pre[i-1];
    cout<<"The resultant array is: "<<"\n";
    for(ll i=1;i<=n;i++)
        cout<<pre[i]<<" ";
}