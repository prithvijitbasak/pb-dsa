// Q: https://www.desiqna.in/dp2 

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1] = arr[0];
    if(n>1)
        dp[2]=max(arr[0],arr[1]);

    for(int i=3;i<=n;i++) {
        // very crucial line 
        dp[i]=max(dp[i-1],dp[i-2]+arr[i-3]);
    }
    cout<<dp[n]<<"\n";
}