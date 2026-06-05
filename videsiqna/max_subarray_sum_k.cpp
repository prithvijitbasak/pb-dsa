// to find the longest subarray size of sum of k
#include <bits/stdc++.h>
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
    int currSum=0;
    
    int maxi=-1;
    unordered_map<int,int> ump;
    ump[0] = -1; // extremely crucial
    for(int i=0;i<n;i++) {
        currSum+=arr[i];
        int need=currSum-k;
        if(ump.find(need) != ump.end()) {
            maxi=max(i-ump[need], maxi);
        } if(ump.find(need) == ump.end()) {
            ump[currSum]=i;
        }
    }
    if ( maxi == -1 )
        cout << "There are no any such subarrays" << "\n";
    else
        cout << "The longest subarray of size k is: " << maxi << "\n";
}
