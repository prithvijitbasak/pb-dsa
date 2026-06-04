#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    unordered_map<int,int> ump;
    for(auto it:arr)
        ump[it]+=1;
    int maxi=-1;
    int mini=INT_MAX;
    int mxel,mnel;
    for(auto it:ump)
    {
        if(maxi<it.second) {
            maxi=it.second;
            mxel=it.first;
        }
        if(mini>it.second) {
            mini=it.second;
            mnel=it.first;
        }
        
    }
    cout<<"The max freq = "<<maxi<<" Element is = "<<mxel<<"\n";
    cout<<"The min freq = "<<mini<<" Element is = "<<mnel<<"\n";
}