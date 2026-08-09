// Q: To find the number of pairs in an array which has maximum sum
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    unordered_map<ll,ll> ump;
    // first we are storing the frequency of all numbers in array
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
        ump[arr[i]]+=1;
    }
    ll lar=arr[1],seclar=INT_MIN;
    for(ll i=2;i<=n;i++) {
        // here we are just updating the largest and second largest values

        if(arr[i]>lar) {
            // whenever we are getting a new largest value
            // then update the old largest with the second largest value 
            // because the current largest will become the second largest.
            seclar=lar;
            lar=arr[i];
        }
        else if(arr[i]>seclar and arr[i]<lar)
            seclar=arr[i];
        
        // cout<<lar<<" "<<seclar<<"\n";
        
    }
    // cout<<lar<<" "<<seclar<<"\n";
    ll ans=0;
    // this is the tricky part
    // if the number of largest values are greater than one then only their pair is valid
    // now the formula to get the number of pairs from n values are n*(n-1)/2
    // because lets say there are 4 people and they want to shake hands 
    // then the 1st person will shake with 3 other 
    // and then 2nd one will shake with 2 other 
    // similary for 3 and 4th person as well.
    // thus its the formula to get the summation from 1 to n-1
    // which is n*(n-1)/2
    if(ump[lar]>1) {
        ll val=ump[lar];
        ans=val*(val-1)/2;
    }
    else {
        ans=ump[lar]*ump[seclar];
    }
    cout<<"The number of pairs with maximum sum is: "<<ans<<"\n";
}