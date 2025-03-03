#include <bits/stdc++.h>
using namespace std;

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.



Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


Constraints:

1 <= m, n <= 100

*/


//Mathematical Approach
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long long ans = 1;
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++)
        {
            ans = (ans * i) / j;
        }
        return ans;
    }
};

/*
Time Complexity: O(min(m,n))
Space Complexity: O(1)
*/


/*
1-D DP Approach(Space Optimized)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[j];

                if (j > 0)
                    left = temp[j - 1];

                temp[j] = up+left;
            }
            dp=temp;
        }
        return dp[n - 1];
    }
};
Time Complexity: O(m*n)
Space Complexity: O(n)

*/


/*
Tabulation Approach

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                if (i > 0) {
                    up = dp[i - 1][j];
                }
                int down = 0;
                if (j > 0) {
                    down = dp[i][j - 1];
                }

                dp[i][j] = up + down;
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

class Solution {
    private:
    long long int recur(int x,int y,int m,int n,vector<vector<int>>& dp)
    {
        if(x==m-1 && y==n-1)
        return 1;

         if(x >= m || y >= n)
            return 0;

        if(dp[x][y]!=-1)
        return dp[x][y];

        int right = recur(x+1,y,m,n,dp);
        int down = recur(x,y+1,m,n,dp);

        return dp[x][y] = right+down;
    }
public:
    int uniquePaths(int m, int n) {
        int x = 0; int y =0 ;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        long long int val = recur(x,y,m,n,dp);
        return val;
    }
};

Time Complexity: O(m*n)
Space Complexity: O(m*n)+O(m*n) = O(m*n)

*/

int main()
{
    int m, n;
    cin >> m >> n;
    Solution obj;
    cout << obj.uniquePaths(m, n) << endl;
    return 0;
}