// we need find the prime factors of a number 
// we will map them 
// like prime1 -> number_of_prime1
// like prime2 -> number_of_prime2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get_sqrt(ll n)
{
    ll prob_ans = -1;
    for (ll i = 1; (i * i) <= n; i++)
    {
        if (i * i <= n)
            prob_ans = i;
    }
    return prob_ans;
}
int main() {
    ll n;
    cin>>n;
    map<ll,ll> mp;
    while(n%2 == 0) {
        mp[2]+=1;
        n/=2;
    }
    for(ll i=3;i<=get_sqrt(n);i+=2) {
        while(n%i==0) {
            mp[i]+=1;
            n/=i;
        }
    }
    if(n>2)
        mp[n]+=1;
    cout<<"The prime factors and their counts are: "<<"\n";
    for(auto it:mp)
        cout<<it.first<<" -> "<<it.second<<"\n";
    cout<<"\n";
}