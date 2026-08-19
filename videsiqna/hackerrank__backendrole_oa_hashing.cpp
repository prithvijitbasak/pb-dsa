// Q: https://www.desiqna.in/16189/backend-engineer-hackerrank-online-test
// we need to find the first k interval of time which 
// everybody can use to relax 
// so we are doing the classic range update trick

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll hour_to_mins(string s) {
    ll res=0;
    ll u1=s[0]-48;
    ll u2=s[1]-48;
    ll val=(u1*10)+u2;
    u1=s[3]-48;
    u2=s[4]-48;
    res+=(val*60)+(u1*10+u2);
    return res;
}
string mins_to_hour(ll val) {
    string s="";
    ll u1=val/60;
    ll u2=val%60;
    if(u1<=9) {
        string str="0"+to_string(u1);
        s+=str;
    }
    else {
        string str=to_string(u1);
        s+=str;
    }
    s+=":";
    if(u2<=9) {
        string str="0"+to_string(u2);
        s+=str;
    }
    else {
        string str=to_string(u2);
        s+=str;
    }

    return s;
}
int main() {
    ll n;
    cin>>n;
    vector<ll> times(1450,0);
    for(ll i=1;i<=n;i++) {
        string name,work,t1,t2;
        cin>>name>>work>>t1>>t2;
        int c1,c2;
        c1=hour_to_mins(t1);
        c2=hour_to_mins(t2);
        times[c1]+=1;
        times[c2+1]-=1;
        
    }
    ll k;
    cin>>k;
    for(ll i=1;i<1450;i++) times[i]+=times[i-1];
    ll cnt=0;
    string ans;
    ll f=0;
    for(ll i=0;i<1440;i++) {
        if(times[i]==0) {
            cnt+=1;
            if(cnt==k) {
                // here i-k+1
                // because we need the index where the cnt=0 started. 
                ans=mins_to_hour(i-k+1);
                f=1;
                break;
            }
        }
        else cnt=0;
    }
    if(f==0) cout<<-1<<"\n";
    else cout<<ans<<"\n";
}