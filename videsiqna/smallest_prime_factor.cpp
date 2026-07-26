// to create a an array such that for every i
// we need to find the smallest prime factor up
// until i

// we will use spf_of_eratosthenes method

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    // this is the value of which we want to know
    // the smallest prime factor value
    cin>>n;
    vector<ll> spf(n+10);
    for(ll i=2;i<=n;i++)
        spf[i]=i;
    for(ll i=2;i*i<=n;i++) {
        // checking if the value of spf until i is still i to check whether 
        // its a prime number or not
        if(spf[i]==i) {
            for(ll j=i*i;j<=n;j+=i) {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
    cout<<"The input should be greater than 1"<<"\n";
    cout<<"The smallest prime factor up until "<<n<<" is : "<<"\n";
    cout<<spf[n]<<"\n";
}