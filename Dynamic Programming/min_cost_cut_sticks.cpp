#include<bits/stdc++.h>
using namespace std;

/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

 

Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<long long>> dp(c + 2, vector<long long>(c + 2, 0));

        for (int i = c; i >= 1; i--) {

            for (int j = 1; j <= c; j++) {

                if (i > j)
                    continue;

                long long mini = INT_MAX;
                for (int ind = i; ind <= j; ind++) {
                    long long ans = (long long)cuts[j + 1] -
                                    (long long)cuts[i - 1] + dp[i][ind - 1] +
                                    dp[ind + 1][j];

                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};

/*

Memoization

class Solution {
    private:
    int func(int i,int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>j)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int mini = INT_MAX;
        for(int ind = i;ind<=j;ind++)
        {
            int cost =
cuts[j+1]-cuts[i-1]+func(i,ind-1,cuts,dp)+func(ind+1,j,cuts,dp);

            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return func(1,c,cuts,dp);
    }
};

Time Complexity : O(N^3)
Space Complexity : O(N^2)+O(N)

*/

/*

Recursion

class Solution {
    private:
    int func(int i,int j,vector<int>& cuts)
    {
        if(i>j)
        return 0;
        int mini = INT_MAX;
        for(int ind = i;ind<=j;ind++)
        {
            int cost = cuts[j+1]-cuts[i-1]+func(i,ind-1,cuts)+func(ind+1,j,cuts);

            mini = min(mini,cost);
        }
        return mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());

        return func(1,c,cuts);
    }
};

Time Complexity : O(exponential)
Space Complexity : O(N)

*/

int main() {
    Solution sol;
    vector<int> cuts1 = {1, 3, 4, 5};
    cout << sol.minCost(7, cuts1) << endl; // Output: 16

    vector<int> cuts2 = {5, 6, 1, 4, 2};
    cout << sol.minCost(9, cuts2) << endl; // Output: 22

    return 0;
}