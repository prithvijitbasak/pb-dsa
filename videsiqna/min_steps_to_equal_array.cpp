// PROBLEM STATEMENT
// =================
// You are given an array 'A'. In one step, you must select the largest element 
// of the array and convert it to the second largest element of the array. 

// Your task is to determine the minimum number of steps required such that all 
// elements in the array become equal.

// Core Rule: 
// All elements in the final array will ultimately reduce down to become equal 
// to the original smallest element of the array.


// CONSTRAINTS
// ===========
// * Array Length (N): 1 <= N <= 10^5
// * Array Elements (A[i]): 1 <= A[i] <= 10^9
// * Time Complexity Expectation: O(N log N) or O(N)
// * Space Complexity: O(N)


// SAMPLE TEST CASES
// =================

// Sample Test Case 1:
// ------------------
// Input: A = [4, 4, 3]
// Output: 2
// Explanation:
// 1. The largest element is 4 (appears twice), and the second largest is 3.
// 2. In Step 1, convert the first '4' to '3'. The array becomes [3, 4, 3].
// 3. In Step 2, convert the remaining '4' to '3'. The array becomes [3, 3, 3].
// 4. All elements are now equal. Total steps = 2.

// Sample Test Case 2:
// ------------------
// Input: A = [1, 2, 3]
// Output: 3
// Explanation:
// 1. The largest element is 3, second largest is 2. 
//    Convert '3' -> '2'. Array becomes [1, 2, 2] (Takes 1 step).
// 2. Now, the largest element is 2 (appears twice), and the second largest is 1.
//    Convert both '2's into '1's sequentially. (Takes 2 steps).
// 3. Total steps = 1 + 2 = 3.

// Sample Test Case 3:
// ------------------
// Input: A = [5, 5, 5]
// Output: 0
// Explanation: 
// All elements in the array are already equal. No operations are required.

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    map<int,int> mp;
    for(auto it:arr)
        mp[it]+=1;
    vector<pair<int,int>> freq;
    for(auto it:mp) {
        freq.push_back({it.first,it.second});
    }
    n=freq.size();
    int ans=0;
    for(int i=n-1;i>0;i--) {
        freq[i-1].second+=freq[i].second;
        ans+=freq[i].second;
    }
    cout<<"Min steps required to complete: "<<ans<<"\n";
}