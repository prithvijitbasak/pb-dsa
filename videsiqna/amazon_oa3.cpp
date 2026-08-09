// Q: https://docs.google.com/document/d/1esfWAWutnC-WEOJT0N9vC3Z5EFkUteCrHCtE8rqetEM/edit?tab=t.0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    unordered_map<ll,ll> ump;
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
        ump[arr[i]]+=1;
    }
    // here we need to find the number of elements which are 
    // divisible by 2 or 3 
    // if any element is appearing just only once then no way all the weights can be cleared
    // any frequency 2 or greater is possible 
    // for(auto it:ump) cout<<it.first<<" -> "<<it.second<<"\n";
    ll flag=0;
    ll steps=0;
    for(auto it:ump) {
        ll val=it.second;
        if(val==1) {
            flag=1;
            break;
        }
        // when the value of val is just divisible by 3 then its the answer
        // but if the val is not then just add 1 
        steps+=val/3;
        if(val % 3 != 0) {
            steps+=1;
        }
    }
    if(flag) cout<<-1<<"\n";
    else {
        cout<<"The minimum steps to carry weight is: "<<steps<<"\n";
    }
}