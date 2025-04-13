#include <bits/stdc++.h>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/

class Solution
{
private:
    bool isAllStars(string &S1, int i)
    {
        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++)
        {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = p.length();
        int m = s.length();

        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);

        prev[0] = true;
        for (int i = 1; i <= n; i++)
        {
            curr[0] = isAllStars(p, i);
            for (int j = 1; j <= m; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    curr[j] = prev[j] | curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

/*
Time Complexity: O(n*m)
Space Complexity: O(n) for storing the dp array.
*/


/*

class Solution {
private:
    bool isAllStars(string& S1, int i) {
        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;


        for(int j=1;j<=n;j++)
        {
            dp[0][j] = false;
        }


        for (int i = 1; i <= m; i++) {
            dp[i][0] = isAllStars(p, i);
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m) for storing the dp array.

*/
/*
class Solution {
private:
    bool recur(string& p, string& s, int ind1, int ind2,
               vector<vector<int>>& dp) {
        if (ind1 == 0 && ind2 == 0)
            return true;

        if (ind1 == 0 && ind2 > 0)
            return false;

        if (ind2 == 0 && ind1 > 0) {
            for (int ii = 0; ii < ind1; ii++) {
                if (p[ii] != '*')
                    return false;
            }
            return true;
        }

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (p[ind1 - 1] == s[ind2 - 1] || p[ind1 - 1] == '?')
            return dp[ind1][ind2] = recur(p, s, ind1 - 1, ind2 - 1, dp);

        if (p[ind1 - 1] == '*') {
            return dp[ind1][ind2] = recur(p, s, ind1 - 1, ind2, dp) ||
                                    recur(p, s, ind1, ind2 - 1, dp);
        }

        return false;
    }

public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return recur(p, s, n, m, dp);
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m) for storing the dp array.

*/

int main()
{
    Solution obj;
    string s = "adceb", p = "*a*b";
    cout << obj.isMatch(s, p) << endl; // Output: 1 (true)
    return 0;
}