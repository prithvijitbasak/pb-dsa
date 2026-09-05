// You are given an array of strings. For each string in the array, calculate
// the sum of matching characters between that string and every
// subsequent string in the array. Return an array containing the sum of
// matching characters for each string, where each element at index i in
// the array corresponds to the sum of matching characters of the ith
// string with every subsequent string.

// Two characters are considered matching if they are the same and occur
// at the same index in both strings. If the length of the two strings being
// compared is not equal, only check up to the length of the shorter string.

// Input:
// N = 3
// X = {"abc", "ade", "bbc"}
// Output: [3, 0, 0]
// Explanation:
// For String "abc"(i = 1), the subsequent strings are "ade" and
// "bbc". The matching characters of "abc" with "ade" is 1 which
// is 'a' at index 1 and the matching characters of "abc" with
// "bbc" is 2 which are 'b' and 'c' at index 2 and 3. The answer
// for "abc" is 1 + 2 = 3
// For String "ade"(i = 2), the subsequent string is "bbc". The
// matching characters of "ade" with "bbc' is 0. The answer for
// "ade" is 0.
// For String "bbc"(i = 3), there are no subsequent strings. The
// answer for "bbc" is 0.

// We can note that the answer for the last string in the input
// array will always be 0 as there are no subsequent strings.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<string> arr(n);
    for(ll i=0;i<n;i++) {
        string s;
        cin>>s;
        arr[i]=s;
    }
    
    map<pair<char,ll>,ll> mp;
    vector<ll> ans(n);
    // for col -> count
    // we will traverse the loop from the end of the array 
    // that is the last string on the array
    // then we will come forward to check how many chartacters at pos j 
    // is appearing or we can say at jth col how many 
    // s[i] chars are appearing 
    // so we have taken the key of map as pair
    // note it that when the key is of type pair then 
    // map will work not the unordered_map in c++
    for(ll i=n-1;i>=0;i--) {
        ll cnt=0; // sum for each index
        string s=arr[i];
        ll sz=s.size();
        for(ll j=0;j<sz;j++) {
            ll val=s[j]-'a';
            cnt=cnt+mp[{s[j],j}];
            mp[{s[j],j}]+=1;
        }
        ans[i]=cnt;
    }
    for(auto it:ans) cout<<it<<" ";
}