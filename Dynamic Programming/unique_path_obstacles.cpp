#include<bits/stdc++.h>
using namespace std;

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

//Space Optimized Approach

typedef long long int ll;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    if (grid[i][j] == 1) {
                        temp[j] = 0;
                    } else {
                        temp[j] = 1;
                    }
                    continue;
                }

                if (grid[i][j] == 1) {
                    temp[j] = 0;
                    continue;
                }
                int up = dp[j];
                int left = (j > 0) ? temp[j - 1] : 0;
                temp[j] = up + left;
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 1 && n == 1) {
            if (obstacleGrid[0][0] == 1)
                return 0;
            else
                return 1;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                int down = 0;
                int right = 0;

                if (i > 0)
                    down = dp[i - 1][j];
                if (j > 0)
                    right = dp[i][j - 1];

                dp[i][j] = down+right;
            }
        }
        return dp[m-1][n-1];
    }
};

Time Complexity: O(m*n)
Space Complexity: O(m*n)

*/

/*

Memoization Approach

class Solution {
private:
    int recur(int m, int n, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (m < 0 || n < 0)
            return 0;

        if (m == 0 && n == 0 && grid[m][n] == 0) {
            return 1;
        }

        if (dp[m][n] != -1)
            return dp[m][n];

        if (grid[m][n] == 1)
            return 0;

        int up = recur(m - 1, n, grid,dp);
        int down = recur(m, n - 1, grid,dp);

        return dp[m][n] = up + down;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        ll val = recur(m - 1, n - 1, obstacleGrid, dp);
        return val;
    }
};

Time Complexity: O(m*n)
Space Complexity: O(m*n) + O(m*n) = O(m*n)

*/

/*

Backtracking Approach

class Solution {
private:
    int recur(int m, int n, vector<vector<int>>& grid) {
        if (m == 0 && n == 0 && grid[m][n]==0) {
            return 1;
        }

        if (m < 0 || n < 0)
            return 0;
        if (grid[m][n] == 1)
            return 0;

        int up = recur(m - 1, n, grid);
        int down = recur(m, n - 1, grid);

        return up + down;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        ll val = recur(m - 1, n - 1, obstacleGrid);
        return val;
    }
};

Time Complexity: O(2^(m+n))
Space Complexity: O(m+n)

*/

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << sol.uniquePathsWithObstacles(grid) << endl;
    return 0;
}