// google OA
// we need to find the maximum sum of product of all a[i]*b[i]
// after arranging a and b in any order. 


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long sum=0;
    for(int i=0;i<n;i++)
        sum+=((long long)a[i]*b[i]);
    cout<<"The maximum sum of products is: "<<sum<<"\n";
}