#include <bits/stdc++.h>
using namespace std;


/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

*/


class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (auto &it : nums)
        {
            sum += it;
        }

        if (sum - target < 0 || (sum - target) % 2 != 0)
            return 0;

        int new_target = (sum - target) / 2;

        vector<int> front(new_target + 1, 0);
        front[0] = 1;
        if (nums[0] <= new_target)
        {
            front[nums[0]] += 1;
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(new_target + 1, 0);
            curr[0] = 1;

            for (int tar = 0; tar <= new_target; tar++)
            {
                int notPick = front[tar];

                int pick = 0;
                if (nums[i] <= tar)
                {
                    pick = front[tar - nums[i]];
                }

                curr[tar] = pick + notPick;
            }
            front = curr;
        }

        return front[new_target];
    }
};

/*
Time Complexity: O(N*target), where N is the size of the array nums.
Space Complexity: O(target)
*/

/*


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto& it : nums) {
            sum += it;
        }

        if (sum - target < 0 || (sum - target) % 2 != 0)
            return 0;

        int new_target =(sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(new_target+1,0));

        for(int i =0;i<n;i++)
        {
            dp[i][0] = 1;
        }

        if(nums[0]<=new_target)
        {
            dp[0][nums[0]] +=1;
        }

        for(int i =1;i<n;i++)
        {
            for(int tar = 0;tar<=new_target;tar++)
            {
                int notPick = dp[i-1][tar];

                int pick = 0;
                if(nums[i]<=tar)
                {
                    pick = dp[i-1][tar-nums[i]];
                }

                dp[i][tar] = pick+notPick;
            }
        }
        return dp[n-1][new_target];
    }
};

Time Complexity: O(N*target), where N is the size of the array nums.
Space Complexity: O(N*target)




class Solution {
    int recur(vector<int>& nums, int target, int ind, int n,vector<vector<int>>&
dp) { if (ind == 0) { if (target == 0 && nums[0] == 0) return 2; else if (target
== 0 || nums[0] == target) return 1; else return 0;
        }

        if(dp[ind][target]!=-1)
        return dp[ind][target];

        int notPick = recur(nums, target, ind - 1, n,dp);
        int pick = 0;
        if (nums[ind] <= target) {
            pick += recur(nums, target - nums[ind], ind - 1, n,dp);
        }
        return dp[ind][target] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto& it : nums) {
            sum += it;
        }

        if (sum - target < 0 || (sum - target) % 2 != 0)
            return 0;
        else {
            int new_target = (sum-target)/2;
            vector<vector<int>> dp(n, vector<int>(new_target + 1, -1));
            return recur(nums, new_target, n - 1, n, dp);
        }
    }
};

Time Complexity: O(N*target), where N is the size of the array nums.
Space Complexity: O(N*target) + O(N) for recursion stack space.

*/


int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}