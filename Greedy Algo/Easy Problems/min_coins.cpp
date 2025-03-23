#include<bits/stdc++.h>
using namespace std;

/*

Given a value V, if we want to make a change for V Rs, and we have an infinite supply of 
each of the denominations in Indian currency, i.e., we have an 
infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, 
what is the minimum number of coins and/or notes needed to make the change.

*/

class Solution
{
    public:
    void findmin(int V)
    {
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
        int n = coins.size();
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            while (V >= coins[i])
            {
                V -= coins[i];
                ans.push_back(coins[i]);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
};
/*
Time Complexity: O(N), where N is the number of denominations.
Space Complexity: O(N)
*/

int main()
{
    Solution s;
    int V = 93;
    s.findmin(V);
    return 0;
}