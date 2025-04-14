#include <bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> prev(2, 0);
        vector<int> prev2(2, 0);
        vector<int> curr(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long long profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[i] + prev2[1], prev[0]);
                }
                curr[buy] = profit;
            }
            prev2 = prev;
            prev = curr;
        }
        return prev[1];
    }
};
/*
Time Complexity: O(n*2) = O(n)
Space Complexity: O(2*2) = O(1)
*/

/*

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));


        for(int i = n-1;i>=0;i--)
        {
            for(int buy =0;buy<=1;buy++)
            {
                long long profit = 0;
                if(buy)
                {
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else
                {
                    profit = max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }

                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

Time Complexity: O(n*2) = O(n)
Space Complexity: O(n*2) = O(n)

*/

/*

class Solution {
    private:
    int recur(vector<int>& prices,int ind,int buy,vector<vector<int>>& dp)
    {
        if(ind>=prices.size())
        return 0;

        if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy]= max(-prices[ind]+recur(prices,ind+1,0,dp),recur(prices,ind+1,1,dp));
        }else
        {
            return dp[ind][buy] = max(prices[ind]+recur(prices,ind+2,1,dp),recur(prices,ind+1,0,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recur(prices,0,1,dp);
    }
};

Time Complexity: O(n*2) = O(n)
Space Complexity: O(n*2) = O(n)
*/

int main()
{
    Solution s;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << s.maxProfit(prices) << endl; // Output: 3
    return 0;
}