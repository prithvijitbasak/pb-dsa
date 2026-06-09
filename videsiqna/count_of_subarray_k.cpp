// very important
// to find the count of subarrays whose sum is less than or equal to k
// the values of arrays are non-negative
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
    int sum=0;
    int count=0;
    for(int i=0,j=0;j<n;j++)
    {
        sum+=arr[j];
        while(sum>k) {
            sum-=arr[i];
            i+=1;
        }
        count+=j-i+1;
    }
    cout<<"The number of such subarrays are: "<<count<<"\n";
}