// to find the largest subarray with sum <= k and arr[i]>=0 (non-negative)
// very important

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int ans=0,sum=0,l=0;
    for(int r=0;r<n;r++) {
        sum+=arr[r];
        while(sum>k) {
            sum-=arr[l];
            l+=1;
        }
        ans=max(ans,r-l+1);
    }
    cout<<"The value of maximum size subarray with sum <=k is: "<<ans<<"\n";
}