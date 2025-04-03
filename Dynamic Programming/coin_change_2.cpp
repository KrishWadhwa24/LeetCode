#include <bits/stdc++.h>
using namespace std;


/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000

*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<unsigned int> front(amount + 1, 0);

        front[0] = 1;

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                front[i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                unsigned int notpick = front[amt];
                unsigned int pick = 0;
                if (coins[i] <= amt)
                {
                    pick = front[amt - coins[i]];
                }

                front[amt] = pick + notpick;
            }
        }
        return front[amount];
    }
};

/*
Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(amount)
*/

/*
Space Optimized Approach:

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> front(amount+1,0);
        for(int i =0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            front[i]=1;
        }
        for(int i = 1;i<n;i++)
        {
            vector<int> curr(amount+1,0);
            curr[0]= 1;
            for(int amt = 0;amt<=amount;amt++)
            {
                long long int pick = 0;
                long long int notpick = front[amt];
                if(coins[i]<=amt)
                {
                    pick = curr[amt-coins[i]];
                }

                curr[amt] = pick+notpick;
            }
            front = curr;
        }
        return front[amount];
    }
};

Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(amount)+O(amount) = O(amount).

*/

/*

Tabulation Approach:

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                unsigned int notpick = dp[ind - 1][amt];
                unsigned int pick = 0;
                if (coins[ind] <= amt) {
                    pick = dp[ind][amt - coins[ind]];
                }

                dp[ind][amt] = pick + notpick;
            }
        }

        return dp[n - 1][amount];
    }
};

Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(N*amount) = O(N*amount).
*/

/*

Memoization Approach:

class Solution {
    private:
    int recur(vector<int>& coins,int amount,int ind,vector<vector<int>>& dp)
    {
        if(amount==0)
        return 1;

        if(ind==0)
        {
            if(amount%coins[0]==0)
            return 1;
            else
            return 0;
        }

        if(dp[ind][amount]!=-1)
        return dp[ind][amount];

        int pick = 0;
        if(coins[ind]<=amount)
        {
            pick +=recur(coins,amount-coins[ind],ind,dp);
        }
        int notpick = recur(coins,amount,ind-1,dp);

        return dp[ind][amount] = pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = recur(coins,amount,n-1,dp);
        return ans;
    }
};

Time Complexity: O(N*amount), where N is the size of the array coins.
Space Complexity: O(N*amount) + O(N) = O(N*amount)

*/

int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << sol.change(amount, coins) << endl; // Output: 4
    return 0;
}