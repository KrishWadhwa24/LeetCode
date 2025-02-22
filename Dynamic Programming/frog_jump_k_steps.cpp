#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be |10-30| + |30-20| = 30, which is minimum.
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Constraints:

1 <= arr.size() <=10^4
1 <= k <= 100
1 <= arr[i] <= 10^4
*/

// Recursive Approach

class Solution
{
private:
    int solve(vector<int> &arr, vector<int> &dp, int n, int k, int ind)
    {
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int minSteps = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = abs(arr[i] - arr[i - j]) + dp[i - j];
                    minSteps = min(minSteps, jump);
                }
            }
            dp[i] = minSteps;
        }
        return dp[n - 1];
    }

public:
    int minCost(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, dp, n, k, n - 1);
    }
};


/*
class Solution
{
private:
    int solve(vector<int> &arr, int n, int k, int ind)
    {
        if (ind == 0)
            return 0;

        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (ind - j >= 0)
            {
                int steps = abs(arr[ind] - arr[ind - j]) + solve(arr, n, k, ind - j);
                minSteps = min(minSteps, steps);
            }
        }
        return minSteps;
    }

public:
    int minCost(vector<int> &arr, int k)
    {
        int n = arr.size();
        return solve(arr, n, k, 0);
    }
};

Time Complexity: O(k^n)
Space Complexity: O(n)

*/

// Dynamic Programming Approach

/*
class Solution
{
    private:
    int solve(vector<int>& arr,vector<int>& dp,int n,int k,int ind)
    {
        if(ind==0)
        return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        int minSteps=INT_MAX;
        for(int j =1;j<=k;j++)
        {
            if(ind-j>=0)
            {
                int steps=abs(arr[ind]-arr[ind-j])+solve(arr,dp,n,k,ind-j);
                minSteps=min(minSteps,steps);
            }
        }
        return dp[ind]=minSteps;
    }
    public:
    int minCost(vector<int>& arr,int k)
    {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(arr,dp,n,k,n-1);
    }
};

Time Complexity: O(n*k)
Space Complexity: O(n) + O(n) = O(n)

*/

// Tabulation Approach


/*
Time Complexity: O(n*k)
Space Complexity: O(n)
*/

int main()
{
    vector<int> arr = {10, 30, 40, 50, 20};
    int k = 3;
    Solution obj;
    cout << obj.minCost(arr, k) << endl;
    return 0;
}
