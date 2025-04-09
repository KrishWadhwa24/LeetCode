#include <bits/stdc++.h>
using namespace std;

/*

You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
Constraints:
1 <= s1.size(), s2.size() <= 10^3
Both strings may contain upper and lower case alphabets.

*/
class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int i = 0; i <= m; i++)
        {
            prev[i] = 0;
        }
        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return maxi;
    }
};

/*
Time Complexity: O(n * m)
Space Complexity: O(m) for dp array
where n is the length of s1 and m is the length of s2.
*/

/*
class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }
        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }
};

Time Complexity: O(n * m)
Space Complexity: O(n * m) for dp array
where n is the length of s1 and m is the length of s2.
*/

/*

class Solution
{
    int recur(string &s1, string &s2, int i, int j, vector<vector<int>> &dp, int &maxLen)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            dp[i][j] = 1 + recur(s1, s2, i - 1, j - 1, dp, maxLen);
            maxLen = max(maxLen, dp[i][j]);
        }
        else
        {
            dp[i][j] = 0;
        }

        recur(s1, s2, i - 1, j, dp, maxLen);
        recur(s1, s2, i, j - 1, dp, maxLen);

        return dp[i][j];
    }

public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        int maxLen = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        recur(s1, s2, n - 1, m - 1, dp, maxLen);

        return maxLen;
    }
};

Time Complexity: O(n * m)
Space Complexity: O(n * m) for dp array
where n is the length of s1 and m is the length of s2.
*/

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution obj;
    cout << obj.longestCommonSubstr(s1, s2) << endl;
    return 0;
}