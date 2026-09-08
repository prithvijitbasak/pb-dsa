// Question:
// Please find the increasing subsequence of size - “3” - Return true if it exists; return false if it does not exist 

// -> [ 18 5 4 3 2 1 8 10] 

// Answer :- True; [(1,8,10) , (5,8,10) , (4,8,10) , (3,8,10) ,(2,8,10)]

// -> [ 5 4 3 2 1 8] 

// Answer :- False. 

// using this method we can only get the answer as true or false 
// if we actually want to calculate the count of triplets then we need to use 
// fenwick tree


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;

    if (n < 3) {
        cout << "false\n";
        return 0;
    }
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    vector<ll> premin(n);
    premin[0]=arr[0];
    for(ll i=1;i<n;i++) {
        premin[i]=min(premin[i-1],arr[i]);
    }
    vector<ll> suffmax(n);
    suffmax[n-1]=arr[n-1];
    for(ll i=n-2;i>=0;i--) {
        suffmax[i]=max(suffmax[i+1],arr[i]);
    }
    ll ans=0;
    for(ll i=1;i<n-1;i++) {
        if(arr[i]>premin[i-1] and arr[i]<suffmax[i+1])
            ans+=1;
    }
    if(ans)
        cout<<"true"<<ans<<"\n";
    else
        cout<<"false"<<"\n";
}