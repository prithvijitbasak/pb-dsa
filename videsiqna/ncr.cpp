// to find the nCr 
// to find the select r items from n items 
// not considering their ordering
#include<bits/stdc++.h>
using namespace std;
int fact(int n) {
    int f=1;
    for(int i=n;i>=1;i--)
        f*=i;
    return f;
}
int main() {
    int n,r;
    cin>>n>>r;
    int res=0;
    int num=fact(n);
    int den=fact(r)*fact(n-r);
    res=num/den;
    cout<<"The value of combination is: "<<"\n";
    cout<<res<<"\n";

}