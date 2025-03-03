#include <bits/stdc++.h>
using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/


//Space Optimized Approach

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = grid[i][j];
                    continue;
                }

                int up = INT_MAX;
                if (i > 0)
                    up = dp[j] + grid[i][j];

                int left = INT_MAX;
                if (j > 0)
                    left = temp[j - 1] + grid[i][j];

                temp[j] = min(up, left);
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};

/*
Time Complexity: O(m*n)
Space Complexity: O(n)
*/

/*
Tabulation Approach

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                    continue;
                }

                int down = grid[i][j];
                int right = grid[i][j];

                if (i > 0)
                    down += dp[i - 1][j];
                else
                    down = INT_MAX;

                if (j > 0)
                    right += dp[i][j - 1];
                else
                    right = INT_MAX;

                dp[i][j] = min(down, right);
            }
        }
        return dp[m - 1][n - 1];
    }
};

Time Complexity: O(m*n)
Space Complexity: O(m*n)

*/

/*
Memoization Approach

typedef long long int ll;
class Solution {
    private:
    ll recur(int m,int n,vector<vector<int>>& grid,vector<vector<ll>>& dp)
    {
        if(m==0 && n==0)
        {
            return grid[0][0];
        }

        if(m<0||n<0)
        return INT_MAX;

        if(dp[m][n]!=-1)
        return dp[m][n];

        ll up = grid[m][n]+recur(m-1,n,grid,dp);
        ll left = grid[m][n]+recur(m,n-1,grid,dp);

        return dp[m][n]=(int)min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> dp(m,vector<ll>(n,-1));

        return recur(m-1,n-1,grid,dp);
    }
};
Time Complexity: O(m*n)
Space Complexity: O(m*n)+O(m*n) = O(m*n)

*/

/*

Backtracking Approach

class Solution {
    private:
    int recur(int m,int n,vector<vector<int>>& grid,int sum)
    {
        if(m==0 && n==0)
        {
            return sum+grid[m][n];
        }

        if(m<0||n<0)
        return INT_MAX;

        int up = recur(m-1,n,grid,sum+grid[m][n]);
        int left = recur(m,n-1,grid,sum+grid[m][n]);

        return min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return recur(m-1,n-1,grid,0);
    }
};

Time Complexity: O(2^(m+n))
Space Complexity: O(m+n)
*/

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}