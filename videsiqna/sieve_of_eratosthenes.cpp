// to find the all prime numbers 
// ranged between 1 to n

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin>>n;;
    vector<ll> primes(n+1,1);
    primes[0]=0;
    primes[1]=0;
    ll half=sqrt(n);
    for(ll i=2;i<=half;i++) {
        if(primes[i]) {
            for(ll j=i*i;j<=n;j+=i) {
                primes[j]=0;
            }
        }
    }
    vector<ll> ans;
    for(ll i=1;i<=n;i++) {
        if(primes[i])
            ans.push_back(i);
    }
    cout<<"The prime values are: "<<"\n";
    for(auto it: ans) 
        cout<<it<<" ";
}