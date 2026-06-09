// to find the subarrays whose count of unique elements
// less than or equal to k

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    unordered_map<int,int> ump;
    int count=0;
    for(int i=0,j=0;j<n;j++)
    {
        ump[arr[j]]+=1;
        int sz=ump.size();
        while(sz>k) {
            ump[arr[i]]-=1;
            if(ump[arr[i]]==0)
                ump.erase(arr[i]);
            i+=1;
            sz=ump.size();
        }
        count+=j-i+1;
    }
    cout<<"The number of such subarrays with unique elements are: "<<count<<"\n";
}