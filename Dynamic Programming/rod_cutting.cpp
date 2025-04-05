#include <bits/stdc++.h>
using namespace std;

/*
Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.
Input: price[] = [1, 10, 3, 1, 3, 1, 5, 9]
Output: 40
Constraints:
1 ≤ price.size() ≤ 10^3
1 ≤ price[i] ≤ 10^6

*/

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> prev(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            prev[i] = i * price[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int len = 0; len <= n; len++)
            {
                int notPick = prev[len];

                int pick = INT_MIN;
                if (i + 1 <= len)
                {
                    pick = price[i] + prev[len - (i + 1)];
                }

                prev[len] = max(pick, notPick);
            }
        }
        return prev[n];
    }
};

/*
Time Complexity: O(N^2)
Space Complexity: O(N)
Where N is the number of items.
*/

/*
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = i * price[0];
        }

        for(int i =1;i<n;i++)
        {
            for(int len = 0;len<=n;len++)
            {
                int notPick = 0 + dp[i-1][len];
                int pick = INT_MIN;
                if(i+1<=len)
                {
                    pick = price[i] + dp[i][len-(i+1)];
                }

                dp[i][len] = max(pick,notPick);
            }
        }
        return dp[n-1][n];
    }
};

Time Complexity: O(N^2)
Space Complexity: O(N^2)
Where N is the number of items.

*/
/*
class Solution {
private:
    int recur(vector<int>& price, int ind, int target,vector<vector<int>>& dp) {
        if(ind == 0) {
            return (target) * price[0];
        }

        if(dp[ind][target]!=-1)
        return dp[ind][target];

        int notPick = recur(price, ind - 1, target,dp);
        int pick = INT_MIN;
        if(ind + 1 <= target) {
            pick = price[ind] + recur(price, ind, target - (ind + 1),dp);
        }
        return dp[ind][target] = max(pick, notPick);
    }

public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recur(price, n - 1, n,dp);
    }
};

Time Complexity: O(N^2)
Space Complexity: O(N^2) + O(N) for recursion stack space.
Where N is the number of items.

*/

int main()
{
    Solution s;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << s.cutRod(price) << endl; // Output: 22
    return 0;
}