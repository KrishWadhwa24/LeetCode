#include <bits/stdc++.h>
using namespace std;

/*

Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Examples:

Input: val = [1, 1], wt = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.
Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.
Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element .hence, total profit is 0.
Constraints:
1 <= val.size() = wt.size() <= 1000
1 <= capacity <= 1000
1 <= val[i], wt[i] <= 100

*/

class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<int> front(capacity + 1, 0);

        for (int i = 0; i <= capacity; i++)
        {
            front[i] = (i / wt[0]) * val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int notPick = 0 + front[w];
                int pick = INT_MIN;
                if (wt[i] <= w)
                {
                    pick = val[i] + front[w - wt[i]];
                }

                front[w] = max(pick, notPick);
            }
        }
        return front[capacity];
    }
};

/*
Time Complexity: O(N*W)
Space Complexity: O(W)
Where N is the number of items and W is the capacity of the knapsack.
*/

/*
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));

        for(int i =0;i<=capacity;i++)
        {
            dp[0][i] = (i/wt[0])*val[0];
        }

        for(int i =1;i<n;i++)
        {
            for(int w =0;w<=capacity;w++)
            {
                int notPick = dp[i-1][w];

                int pick = INT_MIN;
                if(wt[i]<=w)
                {
                    pick =val[i] + dp[i][w-wt[i]];
                }

                dp[i][w] = max(pick,notPick);
            }
        }
        return dp[n-1][capacity];
    }
};
Time Complexity: O(N*W)
Space Complexity: O(N*W)
Where N is the number of items and W is the capacity of the knapsack.

*/

/*

class Solution
{
private:
    int recur(vector<int> &val, vector<int> &wt, int target, int ind, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (wt[0] <= target)
            {
                return (target / wt[0]) * val[0];
            }
            else
                return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = 0 + recur(val, wt, target, ind - 1, dp);
        int take = INT_MIN;

        if (wt[ind] <= target)
        {
            take = val[ind] + recur(val, wt, target - wt[ind], ind, dp);
        }
        return dp[ind][target] = max(take, notTake);
    }

public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        int w = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return recur(val, wt, capacity, n - 1, dp);
    }
};

Time Complexity: O(N*W)
Space Complexity: O(N*W) + O(N) for recursion stack space.
Where N is the number of items and W is the capacity of the knapsack.
*/

int main()
{
    Solution s;
    vector<int> val = {1, 1};
    vector<int> wt = {2, 1};
    int capacity = 3;
    cout << s.knapSack(val, wt, capacity) << endl; // Output: 3

    vector<int> val2 = {6, 1, 7, 7};
    vector<int> wt2 = {1, 3, 4, 5};
    int capacity2 = 8;
    cout << s.knapSack(val2, wt2, capacity2) << endl; // Output: 48

    return 0;
}