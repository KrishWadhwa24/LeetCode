#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10


Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104


Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

// Space Optimized Approach

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> front(n);
        vector<int> curr(n);
        for (int i = 0; i < n; i++)
        {
            front[i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j];
                int right = triangle[i][j] + front[j + 1];

                curr[j] = min(down, right);
            }
            front = curr;
        }
        return front[0];
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)+O(n) = O(n)
*/

/*

Tabulation Approach

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<ll>> dp(n, vector<ll>(n,0));
        for(int i =0;i<n;i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i =n-2;i>=0;i--)
        {
            for(int j =i;j>=0;j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,right);
            }
        }
        return dp[0][0];
    }
};

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

/*
Memoization Approach

typedef long long int ll;
class Solution {
    private:
    int backtrack(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==n-1)
        return triangle[i][j];

        if(dp[i][j]!=-1)
        return dp[i][j];

        int down = triangle[i][j] + backtrack(i+1,j,n,triangle,dp);
        int right = triangle[i][j] + backtrack(i+1,j+1,n,triangle,dp);

        return dp[i][j] = min(down,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        ll sum = backtrack(0,0,n,triangle,dp);
        return sum;
    }
};

Time Complexity: O(n^2)
Space Complexity: O(n^2) + O(n^2) = O(n^2)

*/

/*

Backtracking Approach

typedef long long int ll;
class Solution {
    private:
    int backtrack(int i,int j,int n,vector<vector<int>>& triangle)
    {
        if(i==n-1)
        return triangle[i][j];

        int down = triangle[i][j] + backtrack(i+1,j,n,triangle);
        int right = triangle[i][j] + backtrack(i+1,j+1,n,triangle);

        return min(down,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        ll sum = backtrack(0,0,n,triangle);
        return sum;
    }
};

Time Complexity: O(2^(n^2))
Space Complexity: O(n)

*/

int main()
{
    Solution s;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}