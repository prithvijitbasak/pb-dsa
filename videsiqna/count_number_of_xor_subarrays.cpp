// to find the number of subarrays with xor == k
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    int currXor = 0, ans=0;
    unordered_map<int,int> ump;
    ump[0]=1;
    for(int i=0;i<n;i++) {
        currXor^=arr[i];
        int need = currXor ^ k;
        if(ump.find(need) != ump.end())
            ans+=ump[need];
        ump[currXor]+=1;
    }
    cout<<"The number of subarrays with XOR == k: "<<ans<<"\n";
}