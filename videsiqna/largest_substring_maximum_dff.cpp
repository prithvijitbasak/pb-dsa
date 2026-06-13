// Google OA:
// We need to find the largest substring whose diff between largest character and smallest character
// is <= k

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k; cin>>k;
    int n=s.size();
    deque<char> maxd,mind;
    string ans="";
    int left=0;
    int maxlen=0, bestleft=0;
    for(int i=0;i<n;i++) {
        while(!maxd.empty() and s[i]>maxd.back())
            maxd.pop_back();
        maxd.push_back(s[i]);
        while(!mind.empty() and s[i]<mind.back())
            mind.pop_back();
        mind.push_back(s[i]);
        while (maxd.front()-mind.front()>k)
        {
            if(s[left]==maxd.front())
                maxd.pop_front();
            if(s[left]==mind.front())
                mind.pop_front();
            left+=1;
        }
        int currlen=i-left+1;
        if(currlen>maxlen) {
            maxlen=currlen;
            bestleft=left;
        }
    }
    ans=s.substr(bestleft,maxlen);
    cout<<ans<<"\n";
}