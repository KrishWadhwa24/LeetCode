#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target.

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
Output: true
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 4 x 10^4

*/

// Space Optimised Tabulation

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<bool> prev(target + 1, false), curr(target + 1, false);

        // Base case: sum 0 is always possible
        prev[0] = true;
        if (arr[0] <= target)
            prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            curr[0] = true;
            for (int j = 1; j <= target; j++)
            {
                bool nottake = prev[j];
                bool take = false;
                if (arr[ind] <= j)
                    take = prev[j - arr[ind]];

                curr[j] = take || nottake;
            }
            prev = curr;
        }
        return prev[target];
    }
};

/*
Time Complexity: O(n*target)
Space Complexity: O(target)
*/


/*
// Tabulation

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        dp[0][arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool nottake = dp[ind - 1][j];
                bool take = false;
                if (arr[ind] <= j)
                    take = dp[ind - 1][j - arr[ind]];

                dp[ind][j] = take | nottake;
            }
        }
        return dp[n - 1][target];
    }
};

Time Complexity: O(n*target)
Space Complexity: O(n*target)

*/

/*

// Memoization

class Solution
{
private:
    bool backtrack(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        // Base Case
        if (target == 0)
            return true;

        if (ind == 0)
            return arr[ind] == target;

        if (arr[ind] == target)
            return true;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Take and notTake
        bool take = false;

        if (target >= arr[ind])
            take = backtrack(ind - 1, arr, target - arr[ind], dp);

        if (take)
            return true;
        bool notTake = backtrack(ind - 1, arr, target, dp);
        if (notTake)
            return true;

        return dp[ind][target] = take | notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return backtrack(n - 1, arr, target, dp);
    }
};

Time Complexity: O(n*target)
Space Complexity: O(n*target) + O(n) for recursion stack

*/

/*

// Optimised Backtracking

class Solution
{
private:
    bool backtrack(int ind, vector<int> &arr, int target)
    {
        // Base Case
        if (target == 0)
            return true;

        if (ind == 0)
            return arr[ind] == target;

        if (arr[ind] == target)
            return true;

        // Take and notTake
        bool take = false;

        if (target >= arr[ind])
            take = backtrack(ind - 1, arr, target - arr[ind]);

        if (take)
            return true;

        bool notTake = backtrack(ind - 1, arr, target);

        if (notTake)
            return true;

        return take | notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        return backtrack(n - 1, arr, target);
    }
};

Time Complexity: O(2^n)
Space Complexity: O(1) + O(n) for recursion stack
*/

int main()
{
    Solution s;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << s.isSubsetSum(arr, target) << endl;
    return 0;
}