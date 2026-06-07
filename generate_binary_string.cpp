// to generate all binary string combination of size n
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<string> ans;
    long long total=pow(2,n);
    for(long long i=0;i<total;i++) {
        string str="";
        for(int j=n-1;j>=0;j--) {
            if((i>>j)&1) str+='1'; // main intuition to generate
            else str+='0';
        }
        ans.push_back(str);
    }
    cout<<"All the binary combination are here: "<<"\n";
    for(auto it:ans)
    {
        cout<<it<<"\n";
    }
}