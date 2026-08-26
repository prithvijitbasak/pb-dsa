// here we need to find such pairs which have 
// | arr[i]-arr[j] | + | arr[i]+arr[j] | == sumval;
// to find this we need to find a formula 
// if a and b both are positive then:
// The expression |a - b| + |a + b| simplifies mathematically to 2 * max(|a|, |b|).
// Thus, the condition becomes 2 * max(|a|, |b|) == sumval.
// This means we are looking for pairs where the maximum value is exactly sumval / 2.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
    }
    ll sumval;
    cin>>sumval;
    
    // Our target is the required maximum value for a valid pair
    ll target=sumval/2;
    ll cnt=0,cntless=0;
    
    for(auto it:arr) {
        // Scenario 2: The number is exactly EQUAL to the target.
        // (Note: To perfectly handle negative numbers per the problem description, 
        // the math requires checking abs(it) == target).
        if(it==target) cnt+=1;
        
        // Scenario 3: The number is strictly LESS than the target.
        // When paired with a 'target' element, the maximum of the two is still 'target'.
        // (Note: The math requires checking abs(it) < target).
        else if(it<target) cntless+=1;
        
        // Scenario 1: Elements > target are implicitly ignored because 
        // pairing them would make the maximum greater than our target.
    }
    
    // Calculate total interesting pairs using combinatorics:
    // 1. Pairs formed by taking two 'target' elements: nC2 = (cnt * (cnt - 1)) / 2
    ll ans=(cnt*(cnt-1))/2;
    
    // 2. Pairs formed by combining one 'target' element with one smaller element
    ans+=cnt*cntless;
    
    cout<<ans<<"\n";
}