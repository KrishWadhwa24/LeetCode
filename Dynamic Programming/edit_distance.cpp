#include <bits/stdc++.h>
using namespace std;

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        vector<int> prev(m + 1, 0);
        for (int j = 0; j <= m; ++j)
        {
            prev[j] = j;
        }
        vector<int> curr(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    curr[j] = 1 + min({curr[j - 1], prev[j], prev[j - 1]});
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
/*
Time Complexity: O(n*m)
Space Complexity: O(m)
*/

/*

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[n][m];
    }
};
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/

/*
class Solution {
private:
    int recur(string& word1, string& word2, int ind1, int ind2,
              vector<vector<int>>& dp) {
        // base case
        if (ind1 == 0)
            return ind2;

        if (ind2 == 0)
            return ind1;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (word1[ind1 - 1] == word2[ind2 - 1]) {
            return dp[ind1][ind2] = recur(word1, word2, ind1 - 1, ind2 - 1, dp);
        } else {
            return dp[ind1][ind2] =
                       1 + min({recur(word1, word2, ind1, ind2 - 1, dp),
                                recur(word1, word2, ind1 - 1, ind2, dp),
                                recur(word1, word2, ind1 - 1, ind2 - 1, dp)});
        }
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return recur(word1, word2, n, m, dp);
    }
};
Time Complexity: O(n*m)
Space Complexity: O(n*m)+O(n+m) for recursion stack space

*/

int main()
{
    Solution s;
    string word1 = "horse";
    string word2 = "ros";
    cout << s.minDistance(word1, word2) << endl; // Output: 3
    return 0;
}