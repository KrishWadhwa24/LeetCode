#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
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

        return prev[1][k];
    }
};

/*
Time Complexity: O(n*2*k) = O(n*k)
Space Complexity: O(2*k) = O(k)
*/

int main()
{
    Solution s;
    vector<int> prices = {2, 4, 1, 7, 3, 6};
    int k = 2;
    cout << s.maxProfit(k, prices) << endl; // Output: 7
    return 0;
}