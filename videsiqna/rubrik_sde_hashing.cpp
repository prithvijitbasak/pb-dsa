// we are being given an array of size n 
// which consists of only elements of x and y 
// x and y are given
// we need to find how many subarrays does have equal no of x and y
// here to find the answer we will just apply a trick
// convert all x to -1 and y to 1 
// then we just need to find the number of subarrays 
// whose sum is 0

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    vector<ll> nums(n);
    for(ll i=0;i<n;i++) {
        if(arr[i]==x)
            nums[i]=-1;
        else
            nums[i]=1;
    }
    unordered_map<ll,ll> ump;
    ump[0]=1;
    ll k=0,currsum=0;
    ll ans=0;
    for(ll i=0;i<n;i++) {
        currsum+=nums[i];
        ll need=currsum-k;
        if(ump.find(need)!=ump.end())
            ans+=ump[need];
        ump[currsum]+=1;
    }
    cout<<"The number of subarrays  which have equal number of x and y are: "<<ans<<"\n";
}