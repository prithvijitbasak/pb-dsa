#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a,b,k;
    cin>>a>>b>>k;
    cout<<(a%k + b%k)%k;
    cout<<'\n';
    cout<<((a%k)*(b%k))%k;
    cout<<'\n';
    cout<<(a%k -b%k + k)%k;
    
    
    
    return 0;
}