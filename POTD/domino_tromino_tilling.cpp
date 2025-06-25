#include <bits/stdc++.h>
using namespace std;

/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.



Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 1000

*/

class Solution
{
    int mod = 1e9 + 7;

public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((2 * dp[i - 1] % mod) % mod + dp[i - 3] % mod) % mod;
        }
        return dp[n];
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*

class Solution {
    int mod = 1e9+7;
    private:
    int recur(int n,vector<int>& dp)
    {
        if(dp[n]!=-1)
        return dp[n];
        dp[n] = ((2*recur(n-1,dp)%mod)%mod+recur(n-3,dp)%mod)%mod;
        return dp[n];
    }
public:
    int numTilings(int n) {
        if(n==1)
        return 1;
        if(n==2)
        return 2;
        if(n==3)
        return 5;
        vector<int> dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] =5;
        return recur(n,dp)%mod;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)+O(n) for recursion stack space
*/

int main()
{
    Solution s;
    int n = 999;
    cout << s.numTilings(n) << endl; 
    return 0;
}