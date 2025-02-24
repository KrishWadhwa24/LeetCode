#include <bits/stdc++.h>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

// Optimized Code
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int prev2 = 0;
        int prev1 = nums[1];

        for (int i = 2; i < n; i++)
        {
            int take = nums[i] + prev2;
            int notTake = 0 + prev1;

            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        int maxi1 = prev1;

        prev2 = 0;
        prev1 = nums[0];

        for (int i = 1; i < n - 1; i++)
        {
            int take = nums[i] + prev2;
            int notTake = 0 + prev1;

            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        int maxi2 = prev1;

        return max(maxi1, maxi2);
    }
};

/*
Time Complexity : O(N)
Space Complexity : O(1)
*/

// Tabulation
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n, 0);

        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            int take = nums[i] + (i > 2 ? dp[i - 2] : 0);
            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }
        int maxi1 = dp[n - 1];

        dp.assign(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            int take = nums[i] + (i > 1 ? dp[i - 2] : 0);
            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }
        int maxi2 = dp[n - 2];

        return max(maxi1, maxi2);
    }
};

Time Complexity : O(N)+O(N) = O(N)
Space Complexity : O(N)
*/

// Memoization
/*
class Solution
{
private:
    int recur(vector<int> &nums, int n, int ind, vector<int> &dp)
    {
        if (ind == 0)
            return nums[0];
        if (ind < 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int take = nums[ind] + recur(nums, n, ind - 2, dp);
        int notTake = 0 + recur(nums, n, ind - 1, dp);

        return dp[ind] = max(take, notTake);
    }
    int recur2(vector<int> &nums, int n, int ind, vector<int> &dp)
    {
        if (ind == n - 1)
            return nums[n - 1];

        if (ind >= n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int take = nums[ind] + recur2(nums, n, ind + 2, dp);
        int notTake = 0 + recur2(nums, n, ind + 1, dp);

        return dp[ind] = max(take, notTake);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);
        int maxi = recur(nums, n, n - 2, dp);
        dp.assign(n, -1);
        int maxi2 = recur2(nums, n, 1, dp);
        return max(maxi, maxi2);
    }
};

Time Complexity : O(N)+O(N) = O(N)
Space Complexity : O(N)+O(N) = O(N)

*/

// Brute Force
/*
class Solution
{
private:
    int recur(vector<int> &nums, int n, int ind)
    {
        if (ind == 0)
            return nums[0];
        if (ind < 0)
            return 0;

        int take = nums[ind] + recur(nums, n, ind - 2);
        int notTake = 0 + recur(nums, n, ind - 1);

        return max(take, notTake);
    }
    int recur2(vector<int> &nums, int n, int ind)
    {
        if (ind == n - 1)
            return nums[n - 1];

        if (ind >= n)
            return 0;

        int take = nums[ind] + recur2(nums, n, ind + 2);
        int notTake = 0 + recur2(nums, n, ind + 1);

        return max(take, notTake);
    }
};

Time Complexity : O(2^N)
Space Complexity : O(N)

*/

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.rob(nums) << endl;
    return 0;
}