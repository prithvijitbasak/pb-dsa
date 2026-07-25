// need to find the number of arrays which have 
// all the elements are strictly increasing in order
// the size of the array can be n and range of the elements can be between 
// 1 to m
// answer = mCn
#include<bits/stdc++.h>
using namespace std;
int fact(int n) {
    int f=1;
    for(int i=n;i>=1;i--)
        f*=i;
    return f;
}
int main() {
    int m,n;
    cin>>m>>n;
    int res=0;
    int num=fact(m);
    int den=fact(n)*fact(m-n);
    res=num/den;
    cout<<"The number of arrays which are strictly increasing are: "<<"\n";
    cout<<res<<"\n";
}