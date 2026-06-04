// check whether there are eual elements in a array at a distance of k
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    unordered_map<int,int> ump;
    
    int ok=0;
    for(int i=0;i<n;i++)
    {
        if(ump.find(arr[i])!=ump.end() and abs(ump[arr[i]]-i)<=k) {
            ok=1;
                break;
        }
        ump[arr[i]]=i;
    }
    if(ok)
        cout<<"Yes"<<"\n";
    else    
        cout<<"No"<<"\n";
}