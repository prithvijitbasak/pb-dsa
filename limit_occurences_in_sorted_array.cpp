#include <bits/stdc++.h>
using namespace std;

vector<int> limitOccurrences(vector<int> &nums, int k)
{
    vector<int> ans;
    unordered_map<int, int> ump;
    int n = nums.size();
    for (auto it : nums)
        ump[it] += 1;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!ans.empty() and ans.back() == nums[i])
            i += 1;
        if (ump[nums[i]] > 0)
        {

            if (ump[nums[i]] >= k)
            {
                int temp = k;
                while (temp--)
                    ans.push_back(nums[i]);
            }
            else
            {
                int temp = ump[nums[i]];
                while (temp--)
                    ans.push_back(nums[i]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {5,5};
    vector<int> ans = limitOccurrences(nums, 1);
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}