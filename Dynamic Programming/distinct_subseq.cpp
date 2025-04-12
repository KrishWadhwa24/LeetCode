#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.



Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag


Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

*/

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        vector<double> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                    dp[j] = dp[j - 1] + dp[j];
            }
        }
        return (int)dp[m];
    }
};
/*
Time Complexity: O(n*m)
Space Complexity: O(m)
*/

/*

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<double>> dp(n+1,vector<double>(m+1,0));

        for(int i = 0;i<=n;i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
Time Complexity: O(n*m)
Space Complexity: O(n*m)




class Solution {
private:
    int recur(string& s, string& t, int ind1, int ind2,vector<vector<int>>& dp) {
        if (ind2 == 0)
            return 1;
        if (ind1 == 0)
            return 0;

        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
        if (s[ind1 - 1] == t[ind2 - 1]) {
            return dp[ind1][ind2] =  recur(s, t, ind1 - 1, ind2 - 1,dp) +
                   recur(s, t, ind1 - 1, ind2,dp);
        } else {
            return dp[ind1][ind2] =  recur(s, t, ind1 - 1, ind2,dp);
        }
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recur(s, t, n, m,dp);
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n+m) + O(n*m) for dp array

*/

int main()
{
    Solution obj;
    string s = "rabbbit";
    string t = "rabbit";
    cout << obj.numDistinct(s, t) << endl; // Output: 3
    return 0;
}