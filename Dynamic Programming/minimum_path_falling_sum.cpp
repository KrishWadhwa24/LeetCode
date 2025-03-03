#include <bits/stdc++.h>
using namespace std;

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).



Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = matrix[0][i];

        for (int i = 1; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                int left = j > 0 ? dp[j - 1] : INT_MAX;
                int right = j < n - 1 ? dp[j + 1] : INT_MAX;
                int up = dp[j];

                temp[j] = matrix[i][j] + min({left, right, up});
            }
            dp = temp;
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, dp[i]);
        }
        return mini;
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int left = (j > 0 ? dp[i - 1][j - 1] : INT_MAX);
                int up = dp[i - 1][j];
                int right = (j < n - 1 ? dp[i - 1][j + 1] : INT_MAX);

                dp[i][j] = matrix[i][j] + min({left, up, right});
            }
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, dp[m - 1][i]);
        }
        return mini;
    }
};

Time Complexity: O(m*n)
Space Complexity: O(m*n)

*/

/*

Memoization Approach

class Solution {
private:
    int backtrack(int i, int j, int m, int n, vector<vector<int>>&
matrix,vector<vector<int>>& dp) { if (i == m - 1) return matrix[i][j];

        if(dp[i][j]!=-1)
        return dp[i][j];
        int left = INT_MAX, down = INT_MAX, right = INT_MAX;

        if (j - 1 >= 0)
            left = matrix[i][j] + backtrack(i + 1, j - 1, m, n, matrix,dp);

        down = matrix[i][j] + backtrack(i + 1, j, m, n, matrix,dp);

        if (j + 1 < n)
            right = matrix[i][j] + backtrack(i + 1, j + 1, m, n, matrix,dp);

        return dp[i][j]= min({left, down, right});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, backtrack(0, j, m, n, matrix,dp));
        }

        return result;
    }
};

Time Complexity: O(m*n)
Space Complexity: O(m*n)+O(m*n)=O(m*n)

*/

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << s.minFallingPathSum(matrix) << endl;
    return 0;
}