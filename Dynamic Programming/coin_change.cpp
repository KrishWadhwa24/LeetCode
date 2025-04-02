#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4


*/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<int> front(amount + 1, INT_MAX - 1);

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                front[i] = i / coins[0];
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int notTake = front[amt];
                int take = INT_MAX - 1;
                if (coins[i] <= amt)
                {
                    take = 1 + front[amt - coins[i]];
                }

                front[amt] = min(take, notTake);
            }
        }
        return front[amount] == INT_MAX - 1 ? -1 : front[amount];
    }
};

/*
Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(amount)
*/


/*
Space Optimized Approach :

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> front(amount + 1, INT_MAX - 1);

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                front[i] = i / coins[0];
            }
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(amount + 1, INT_MAX - 1);
            for(int amt = 0;amt<=amount;amt++)
            {
                int notTake = front[amt];
                int take = INT_MAX-1;
                if (coins[i] <= amt)
                {
                    take = 1+curr[amt-coins[i]];
                }

                curr[amt] = min(take,notTake);
            }
            front = curr;
        }
        return front[amount]==INT_MAX-1?-1:front[amount];
    }
};

Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(amount*2) = O(amount).

*/

/*
Tabulation Approach:

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX - 1));

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 0; amt <= amount; amt++) {
                int take = INT_MAX - 1;
                if (coins[i] <= amt) {
                    take = 1 + dp[i][amt - coins[i]];
                }

                int notTake = dp[i - 1][amt];

                dp[i][amt] = min(take, notTake);
            }
        }
        return dp[n - 1][amount] == INT_MAX - 1 ? -1 : dp[n - 1][amount];
    }
};

Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(N*amount) = O(N*amount).
*/

/*
Memoization Approach:

class Solution {
    private:
    int recur(vector<int>& coins,int amount,int n,int ind,vector<vector<int>>& dp)
    {
        if (amount == 0) return 0;
        if (ind < 0 || amount < 0) return INT_MAX-1;

        if(dp[ind][amount]!=-1)
        return dp[ind][amount];

        int take = INT_MAX;
        int notTake = recur(coins,amount,n,ind-1,dp);
        if(coins[ind]<=amount)
        {
            take = 1+recur(coins,amount-coins[ind],n,ind,dp);
        }

        return dp[ind][amount] = min(take,notTake);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = recur(coins,amount,n,n-1,dp);
        return ans==INT_MAX-1?-1:ans;
    }
};

Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(N*amount) + O(N) = O(N*amount)

*/

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << s.coinChange(coins, amount) << endl; // Output: 3
    return 0;
}