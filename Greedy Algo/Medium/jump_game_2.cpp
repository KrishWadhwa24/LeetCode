#include <bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;
        while (r < n - 1)
        {
            int farthest = 0;
            for (int i = l; i <= r; i++)
            {
                farthest = max(i + nums[i], farthest);
            }
            l = r + 1;
            jumps = jumps + 1;
            r = farthest;
        }
        return jumps;
    }
};

/*
Time Complexity: O(N), where N is the number of elements in the array.
Space Complexity: O(1)
*/

/*
Memoization
class Solution {
private:
    int solve(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= nums[start]; i++) {
            ans = min(ans, 1 + solve(nums, start + i, end, dp));
        }
        return dp[start][end] = ans;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, 0, n - 1, dp);
    }
};

Time Complexity: O(N^2), where N is the number of elements in the array.
Space Complexity: O(N)
*/

/*
Backtracking

class Solution {
private:
    int solve(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= nums[start]; i++) {
            ans = min(ans, 1 + solve(nums, start + i, end));
        }
        return ans;
    }
public:
    int jump(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};

Time Complexity: O(N^N), where N is the number of elements in the array.
Space Complexity: O(N)

*/
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums) << endl;
    return 0;
}