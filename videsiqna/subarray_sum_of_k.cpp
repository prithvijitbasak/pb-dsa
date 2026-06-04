// to find number of subarray of sum of size k
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    int ans=0;
    unordered_map<int,int> ump;
    ump[0]=1; // extremely crucial
    int currSum=0;
    for(int i=0;i<n;i++)
    {
        currSum+=arr[i];
        int need=currSum-k;
        if(ump.find(need) != ump.end())
            ans+=ump[need];
        ump[currSum]+=1;
    }
    cout<<"The number of subarrays with sum ==  k: "<<ans<<"\n";
}