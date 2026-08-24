// You are given an integer array A of size N. Your task is to select exactly B elements
// from either the left end or the right end of the array A in order to maximize the sum of
// the selected elements.

// Here are the details of the problem:

// You are given an integer array A of size N where 1 <= N <= 10^5.
// You need to select exactly B elements from either the left end or the right end of the
// The goal is to find and return the maximum possible sum of elements you can pick.

// Input:

// An integer array A of size N where each element A[i] satisfies -103 <= A[i] <= 103.
// An integer B where 1 <= B <= N.
// Output:

// An integer representing the maximum possible sum of selected elements.

// [5, -2, 3, 1, 2], 3 -> 8

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin>>n;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    ll b;
    cin>>b;
    ll curr=0;
    // we are thinking that
    // we will take the sum of first b elements from left
    for(ll i=1;i<=b;i++) {
        curr+=arr[i];
    }
    ll ans=curr;
    ll left=b,right=n;
    for(ll i=1;i<=b;i++) {
        // Drop the right-most element from the left prefix
        curr-=arr[left];
        // Add the left-most element from the right suffix
        curr+=arr[right];
        ans=max(ans,curr);
        // Move the left pointer backwards
        left-=1;
        // Move the right pointer backwards
        right-=1;
    }
    cout<<ans<<"\n";
}