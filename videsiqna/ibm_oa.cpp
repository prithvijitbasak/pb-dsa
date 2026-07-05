// ibm_oa
// we need to find the minimum number of operations to change
// every value of array to target element
// either by increasing or decreasing by 1
// for every query
// this can be done by brute force  but we need optimised.
// we need to know what will be the number of operations if target is greater than every elements
// same for lesser elements

// taken from leetcode 2602
typedef long long ll;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<ll> ans;
        ll n =nums.size();
        sort(nums.begin(),nums.end());
        vector<ll> presum(n,0);
        presum[0]=nums[0];
        for(ll i=1;i<n;i++) {
            presum[i]=presum[i-1]+nums[i];
        }
        for(auto it: queries) {
            ll target=it;
            auto itr=upper_bound(nums.begin(),nums.end(), target);
            ll idx=itr-nums.begin();
            ll sum_of_left_half=idx==0 ? 0 : presum[idx-1];
            ll sum_of_right_half=presum[n-1] - sum_of_left_half;
            // to find the no of opt to make left half to target
            ll opt1=idx*target - sum_of_left_half;
            // to find the no of opt to make right half to target
            ll opt2=sum_of_right_half - (n-idx)*target;
            ans.push_back(opt1+opt2);
        }
        return ans;
    }
};