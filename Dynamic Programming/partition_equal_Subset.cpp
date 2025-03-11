#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

// Space Optimized

typedef long long int ll;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        ll sum = 0;
        for (auto &it : nums)
            sum += it;

        if (sum % 2 != 0)
            return false;

        ll k = sum / 2;
        vector<bool> prev(k + 1, false);
        prev[0] = true;

        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(k + 1, false);
            curr[0] = true;
            for (int target = 1; target <= k; target++)
            {
                bool notTake = prev[target];
                bool take = false;

                if (nums[i] <= target)
                    take = prev[target - nums[i]];

                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
};

/*
Time Complexity: O(n*target)
Space Complexity: O(target)+ O(target) = O(target)
*/

/*
Tabulation

typedef long long int ll;
class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        for (auto& it : nums)
            sum += it;

        if (sum % 2 != 0)
            return false;

        ll k = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (nums[0] <= k)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (nums[i] <= target)
                    take = dp[i - 1][target - nums[i]];

                dp[i][target] = take | notTake;
            }
        }
        return dp[n - 1][k];
    }
};

Time Complexity: O(n*target)
Space Complexity: O(n*target) + O(n) = O(n*target)

*/

/*
Memoization

typedef long long int ll;
class Solution {
private:
    bool backtrack(vector<int>& nums, int n, int target, int ind,
                   vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (ind == 0)
            return nums[0] == target;
        if (target < 0)
            return false;
        if (nums[ind] == target)
            return true;
        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = backtrack(nums, n, target, ind - 1, dp);
        bool take = false;
        if (nums[ind] <= target)
            take = backtrack(nums, n, target - nums[ind], ind - 1, dp);

        return dp[ind][target] = take | notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        for (auto& it : nums)
            sum += it;

        if (sum % 2 != 0)
            return false;
        else {
            ll target = sum / 2;
            vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
            return backtrack(nums, n, sum / 2, n - 1, dp);
        }
    }
};

Time Complexity: O(n*target)
Space Complexity: O(n*target) + O(n) + O(n) = O(n*target)

*/

/*

//Backtracking
typedef long long int ll;
class Solution {
private:
    bool backtrack(vector<int>& nums, int n, int target, int ind) {
        if (target == 0)
            return true;
        if (ind == 0)
            return nums[0] == target;
        if (target < 0)
            return false;
        if (nums[ind] == target)
            return true;

        bool notTake = backtrack(nums, n, target, ind - 1);
        bool take = false;
        if (nums[ind] <= target)
            take = backtrack(nums, n, target - nums[ind], ind - 1);

        return take | notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        for (auto& it : nums)
            sum += it;

        if (sum % 2 != 0)
            return false;
        else
            return backtrack(nums, n, sum / 2, n - 1);
    }
};

Time Complexity: O(2^n)
Space Complexity: O(n)

*/

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    Solution s;
    cout << s.canPartition(nums);
    return 0;
}