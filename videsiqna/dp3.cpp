// Q: https://www.desiqna.in/dp3

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=max(a[0],b[0]);
    if(n>1)
        dp[2]=max(max(a[1],b[1]),dp[1]);
    for(int i=3;i<=n;i++)
        dp[i]=max(dp[i-1],dp[i-2]+max(a[i-1],b[i-1]));
    cout<<dp[n]<<"\n";
}