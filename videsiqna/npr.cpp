// to find the nCr 
// to find the select r items from n items 
// considering their ordering (its very imp)

// the formula becomes (n! / r!*(n-r)!) * r!
// then it gets reduced to (n! / *(n-r)!) which is nPr
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
    int den=fact(n-r);
    res=num/den;
    cout<<"The value of permutation is: "<<"\n";
    cout<<res<<"\n";

}