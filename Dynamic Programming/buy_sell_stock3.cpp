#include <bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^5

*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        profit = max(-prices[i] + prev[0][cap], prev[1][cap]);
                    }
                    else
                    {
                        profit = max(prices[i] + prev[1][cap - 1], prev[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            prev = curr;
        }

        return prev[1][2];
    }
};

/*
Time Complexity: O(n*2*3) = O(n)
Space Complexity: O(2*3) = O(1)
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    } else {
                        profit = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};
Time Complexity: O(n*2*3) = O(n)
Space Complexity: O(n*2*3) = O(n)

*/

/*

class Solution {
private:
    int recur(vector<int>& prices, int ind, int cap, int buy, int n,vector<vector<vector<int>>>& dp) {
        if (cap == 0)
            return 0;
        if (ind == n)
            return 0;

        if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
        if (buy) {
            return dp[ind][buy][cap] = max(-prices[ind] + recur(prices, ind + 1, cap, 0, n,dp),
                       0 + recur(prices, ind + 1, cap, 1, n,dp));
        } else {
            return dp[ind][buy][cap] = max(prices[ind] + recur(prices, ind + 1, cap - 1, 1, n,dp),
                       0 + recur(prices, ind + 1, cap, 0, n,dp));
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 3;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return recur(prices, 0, 2, 1, n,dp);
    }
};

Time Complexity: O(n*2*3) = O(n)
Space Complexity: O(n*2*3) = O(n)

*/

int main()
{
    Solution s;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(prices) << endl; // Output: 6

    return 0;
}