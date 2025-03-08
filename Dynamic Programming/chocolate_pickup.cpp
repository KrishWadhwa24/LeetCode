#include <bits/stdc++.h>
using namespace std;

/*
You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
Example:

Input:
n = 4, m = 3
grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output:
24
Explanation:
Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.
Expected Time Complexity: O(n * m * m)
Expected Space Complexity: O(n * m * m)

Constraint:
2 <= n, m < = 70
0 <= grid[i][j] <= 100
*/

// Space Optimized Approach

class Solution
{
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                {
                    front[j1][j2] = grid[n - 1][j1];
                }
                else
                {
                    front[j1][j2] = grid[n - 1][j2] + grid[n - 1][j1];
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }

                            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            {
                                value += front[j1 + dj1][j2 + dj2];
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m - 1];
    }
};

/*
Time Complexity: O(n * m * m) * 9
Space Complexity: O(m * m) + O(m * m) = O(m * m)
*/


/*
// Tabulation

class Solution
{
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                {
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                }
                else
                {
                    dp[n - 1][j1][j2] = grid[n - 1][j2] + grid[n - 1][j1];
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }

                            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};

Time Complexity: O(n * m * m) * 9
Space Complexity: O(n * m * m)


*/


/*

//Memoization Approach
class Solution
{
private:
    int backtrack(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                if (j1 == j2)
                {
                    maxi = max(maxi, grid[i][j1] + backtrack(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp));
                }
                else
                {
                    maxi = max(maxi, (grid[i][j1] + grid[i][j2] + backtrack(i + 1, dj1 + j1, dj2 + j2, n, m, grid, dp)));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return backtrack(0, 0, m - 1, n, m, grid, dp);
    }
};


Time Complexity: O(n * m * m) * 9
Space Complexity: O(n * m * m) + O(n * m * m) = O(n * m * m)


*/

int main()
{
    Solution s;
    int n = 4;
    int m = 3;
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    cout << s.solve(n, m, grid) << endl;
    return 0;
}