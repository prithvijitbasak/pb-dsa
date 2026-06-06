// extremely important amazon OA
// we need to find count of such subarrays whose sum(i.....j)%k == length(i...j) (length of subarray)

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
    int k; cin>>k;
    unordered_map<int,int> ump;
    ump[0]=1;
    int ans=0;
    int currSum=0;
    for(int i=0;i<n;i++) {
        currSum+=arr[i];
        int target=(currSum-i-1)%k; // extremely important line
        if(target<0)
            target+=k;
        if(ump.find(target)!=ump.end())
            ans+=ump[target];
        ump[target]+=1;
    }
    cout<<"The count of such subarrays are: "<<ans<<"\n";
}

// gemini - https://gemini.google.com/share/f395c80d098c