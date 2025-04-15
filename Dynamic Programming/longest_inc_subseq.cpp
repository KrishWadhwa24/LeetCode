#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 0;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (maxi < dp[i])
            {
                maxi = dp[i];
                last = i;
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
        for (auto &it : ans)
            cout << it << " ";

        cout << endl;

        return maxi;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
where n is the length of the input array nums.
*/

/*
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> front(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int len = front[prev + 1];
                if (prev == -1 || nums[i] > nums[prev])
                {
                    len = max(len, 1 + front[i + 1]);
                }
                curr[prev + 1] = len;
            }
            front = curr;
        }
        return front[0];
    }
};

Time Complexity: O(n^2)
Space Complexity: O(n)
where n is the length of the input array nums.
*/

/*

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i = n-1;i>=0;i--)
        {
            for (int prev = i - 1; prev >= -1; prev--) {
                int len = dp[i + 1][prev + 1];
                if (prev == -1 || nums[i] > nums[prev]) {
                    len = max(len, 1 + dp[i + 1][i + 1]);
                }
                dp[i][prev + 1] = len;
            }
        }
        return dp[0][0];
    }
};

Time Complexity: O(n^2)
Space Complexity: O(n^2)
where n is the length of the input array nums.
*/

/*

class Solution {
private:
    int recur(vector<int>& nums, int n, int ind, int prev, vector<vector<int>>& dp) {
        if (ind >= n)
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev+1];
        int len = 0;
        len = max(len, recur(nums, n, ind + 1, prev,dp));

        if (prev == -1 || nums[ind] > nums[prev]) {
            len = max(len, 1 + recur(nums, n, ind + 1, ind,dp));
        }
        return dp[ind][prev + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return recur(nums, n, 0, -1, dp);
    }
};

Time Complexity: O(n^2)
Space Complexity: O(n^2)
where n is the length of the input array nums.

*/

int main()
{
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl; // Output: 4
    return 0;
}