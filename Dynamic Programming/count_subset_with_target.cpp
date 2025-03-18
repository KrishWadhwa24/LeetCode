#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.
Constraints:
1 ≤ arr.size() ≤ 10^3
0 ≤ arr[i] ≤ 10^3
0 ≤ target ≤ 10^3

*/

// Space Optimized Approach:

class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int> front(target + 1, 0);

        front[0] = 1;
        if (arr[0] <= target)
        {
            front[arr[0]] += 1;
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(target + 1, 0);
            curr[0] = 1;
            for (int k = 0; k <= target; k++)
            {
                int notTake = front[k];
                int take = 0;
                if (arr[i] <= k)
                {
                    take = front[k - arr[i]];
                }

                curr[k] = (take + notTake);
            }
            front = curr;
        }

        return front[target];
    }
};

/*
Time Complexity: O(N*target), where N is the size of the array arr.
Space Complexity: O(target).
*/

/*
Tabulation Approach:

class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // First row initialization
        if (arr[0] <= target) {
            dp[0][arr[0]] += 1;
        }

        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= target; k++) {
                int notTake = dp[i - 1][k];
                int take = 0;
                if (arr[i] <= k) {
                    take = dp[i - 1][k - arr[i]];
                }

                dp[i][k] = (take + notTake) ;
            }
        }

        return dp[n - 1][target];
    }
};

Time Complexity: O(N*target), where N is the size of the array arr.
Space Complexity: O(N*target)

*/

/*
Memoization Approach:


class Solution {
private:
    int backtrack(vector<int>& nums, int ind, int target,vector<vector<int>>& dp)
{
    if(ind < 0) {
            return target == 0;
    }
    if(dp[ind][target]!=-1)
    return dp[ind][target];

    int notTake = backtrack(nums, ind-1, target,dp);
    int take = 0;
    if(nums[ind] <= target)
        take = backtrack(nums, ind-1, target-nums[ind],dp);

    return dp[ind][target]= take + notTake;
}
public:
    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return backtrack(arr, n-1, target,dp);
    }
};

Time Complexity: O(N*target), where N is the size of the array arr.
Space Complexity: O(N*target) + O(N) = O(N*target).

*/

/*
Backtracking Approach:


class Solution {
private:
    int backtrack(vector<int>& nums, int ind, int target,vector<vector<int>>& dp)
{
    if(ind < 0) {
            return target == 0;
    }
    if(dp[ind][target]!=-1)
    return dp[ind][target];

    int notTake = backtrack(nums, ind-1, target,dp);
    int take = 0;
    if(nums[ind] <= target)
        take = backtrack(nums, ind-1, target-nums[ind],dp);

    return dp[ind][target]= take + notTake;
}
public:
    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return backtrack(arr, n-1, target,dp);
    }
};

Time Complexity: O(2^N), where N is the size of the array arr.
Space Complexity: O(N).
*/

int main()
{
    Solution sol;
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;
    cout << sol.perfectSum(arr, target) << endl;

    arr = {2, 5, 1, 4, 3};
    target = 10;
    cout << sol.perfectSum(arr, target) << endl;

    arr = {5, 7, 8};
    target = 3;
    cout << sol.perfectSum(arr, target) << endl;

    arr = {35, 2, 8, 22};
    target = 0;
    cout << sol.perfectSum(arr, target) << endl;

    return 0; 
}