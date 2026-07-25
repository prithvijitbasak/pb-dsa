// to find the number of such arrays
// where elements can range from 1 to m
// and the size of the array can be 1 to n


#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int num=pow(m,n);
    cout<<"Number of arrays can be: "<<num<<"\n";
}