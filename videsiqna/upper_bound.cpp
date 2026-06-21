// we have to find the index of the element
// which is just greater than target 
// we will be provided a sorted array

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int target;
    cin>>target;

    // using tradition binary search technique
    int ans=-1;
    // int left=0,right=n-1;
    // while(left<=right) {
    //     int mid=left+(right-left)/2;
    //     if(arr[mid]>target) {
    //         right=mid-1;
    //         ans=mid;
    //     }
    //     else 
    //         left=mid+1;
    // }
    auto up = upper_bound(arr.begin(), arr.end(), target);
    ans=up-arr.begin();
    if(ans < n)
        cout<<"The upper bound is: "<<ans<<"\n";
    else
        cout<<"There is no such elements";
}