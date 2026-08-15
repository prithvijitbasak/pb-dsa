// Editorial - https://share.gemini.google/CzkMUbjARnIw 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll q,v;
    cin>>q>>v;
    // we need a min heap because 
    // for every plugs the value of charge at ti time is wi 
    // then at any time t the value after charging will be 
    // wi+(tquery-ti) or 
    //  w_{plug} + (t_{query} - t_{plug})
    // rearranging these we get = t_{query} - (t_{plug} - w_{plug})
    // so in order to get the maximum value we need to  minimise the t_{plug} - w_{plug}
    // thats why we need minheap to get the min value every time. 
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while(q--) {
        ll type;
        cin>>type;
        if(type==1) {
            ll t,w;
            cin>>t>>w;
            pq.push(t - w);
        }
        else {
            ll t;
            cin>>t;
            if(pq.empty())
                cout<<-1<<"\n";
            else {
                ll cmin=pq.top();
                pq.pop();
                ll ans=min(v,t-cmin);
                cout<<ans<<"\n";
            }
        }
    }
}