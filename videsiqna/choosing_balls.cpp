// we need to find how many ways are there to choose 
// n balls and put them into k boxes.

// very imp formula
// (n+k-1)C(k-1)
// main condition is the balls should be identical and not distinct 
// if the balls are distinct then its k^n ways
// this is stars and bar trick
// main trick is we just need to find the ways of putting the partition 
// such that the position becomes k after partitioning 
// for example if there are k boxes then 
// creating n+k empty areas for putting boxes and partition sticks 
// now if there are 3 boxes and 5 balls to create box places we need 7 places empty
// and in 2 places we will place the sticks which woudl create 3 places to add 5 balls 
// thus the formula comes

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