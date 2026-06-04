// to create 
// E
// D E
// C D E
// D E F G
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int cnt=1;
    for(int i=n;i>=1;i--) {
        char ch='A';
        ch=ch+(i-1);
        for(int j=1;j<=cnt;j++) {
            cout<<ch<<" ";
            ch=ch+1;
        }
        cnt+=1;
        cout<<"\n";
    }   
}