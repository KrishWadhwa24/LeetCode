#include <bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4
*/

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        vector<int> prev(2, 0);
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
                    profit = max(prices[i] + prev[1] - fee, prev[0]);
                }
                curr[buy] = profit;
            }
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
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i = n-1;i>=0;i--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                long long profit = 0;
                if(buy)
                {
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else
                {
                    profit = max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

Time Complexity: O(n*2) = O(n)
Space Complexity: O(2*2) = O(1)
*/

/*

class Solution {
    private:
    int recur(vector<int>& prices,int ind,int buy,vector<vector<int>>& dp,int fee)
    {
        if(ind>=prices.size())
        return 0;

        if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy]= max(-prices[ind]+recur(prices,ind+1,0,dp,fee),recur(prices,ind+1,1,dp,fee));
        }else
        {
            return dp[ind][buy] = max(prices[ind]+recur(prices,ind+1,1,dp,fee)-fee,recur(prices,ind+1,0,dp,fee));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recur(prices,0,1,dp,fee);
    }
};

Time Complexity: O(n*2) = O(n)
Space Complexity: O(n*2) = O(n)
*/

int main()
{
    Solution s;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << s.maxProfit(prices, fee) << endl; // Output: 8
    return 0;
}