// we need to find how many ways are there to choose 
// n balls and put them into k boxes.

// very imp formula
// (n+k-1)C(k-1)
// main condition is the balls should be identical and not distinct 
// if the balls are distinct then its k^n ways
// this is stars and bar trick
// video - https://drive.google.com/file/d/1YqKzjNopb-94Wqm2ZaSMVd-eT4Jj3vkP/view

#include<bits/stdc++.h>
using namespace std;
int fact(int n) {
    int fact=1;
    for(int i=n;i>=1;i--)
        fact*=i;
    return fact;
}
int main() {
    int n,k;
    cin>>n>>k;
    int res=0;
    int num=fact(n+k-1);
    int den=fact(k-1)*fact((n+k-1)-(k-1));
    res=num/den;
    cout<<"The ways of distributing the balls are: "<<"\n";
    cout<<res<<"\n";
}