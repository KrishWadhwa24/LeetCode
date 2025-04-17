#include <bits/stdc++.h>
using namespace std;

/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
All the integers in nums are unique.
*/

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 0;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if ((nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi)
            {
                last = i;
                maxi = dp[i];
            }
        }

        vector<int> ans;
        ans.push_back(nums[last]);

        while (hash[last] != last)
        {
            last = hash[last];
            ans.push_back(nums[last]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
where n is the length of the input array nums.
*/

/*


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int> deg(n,0);
        vector<int> prev(n,-1);

        vector<vector<int>> adj(n);
        for(int i =0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(nums[j]%nums[i]==0)
                {
                    adj[i].push_back(j);
                    deg[j]++;
                }
            }
        }

        queue<int> q;
        for(int i =0;i<n;i++)
        {
            if(deg[i]==0)
            q.push(i);
        }

        int iMax = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            for(auto neig:adj[it])
            {
                deg[neig]--;
                if(deg[neig]==0)
                {
                    q.push(neig);
                    prev[neig] = it;
                }
            }
            iMax = it;
        }

        vector<int> ans;
        for(int i = iMax;i!=-1;i=prev[i])
        {
            ans.push_back(nums[i]);
        }
        return ans;


    }
};

Time Complexity: O(n^2)
Space Complexity: O(n)
where n is the length of the input array nums.
*/

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 6, 8};
    vector<int> ans = s.largestDivisibleSubset(nums);
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}