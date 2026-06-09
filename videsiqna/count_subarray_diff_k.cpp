// to find the count of pair in array such that the absolute diff is <= k
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int count=0;
    sort(arr.begin(),arr.end());
    for(int i=0,j=0;j<n;j++) {
        int diff = arr[j]-arr[i];
        while(diff>k) {
            i+=1; // important line increment i before calculating diff
            diff=arr[j]-arr[i];
        }
        count+=(j-i+1);
    }
    cout<<"The number of pair of unique elements whose absolute diff is <=k are: "<<count-n<<"\n"; 
    // count - n is printed to remove the single elements. 
}