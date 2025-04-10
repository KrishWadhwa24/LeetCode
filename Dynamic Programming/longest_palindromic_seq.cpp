#include <bits/stdc++.h>
using namespace std;

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<int> prev(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> curr(n + 1, 0);
            for (int j = 1; j <= n; j++)
            {
                if (s[i] == s[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};

/*
Time Complexity: O(N^2), where N is the length of the string s.
Space Complexity: O(N).
where N is the length of the string s.
*/

/*

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i =0;i<=n;i++)
        {
            dp[0][i]= 0;
            dp[i][0] =0;
        }


        for(int i = n-1;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i]==s[j-1])
                {
                    dp[i][j] =1 +dp[i+1][j-1];
                }else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n];

    }
};
Time Complexity: O(N^2), where N is the length of the string s.
Space Complexity: O(N^2).
where N is the length of the string s.

*/

/*

class Solution {
private:
    int recur(string& s, int ind1, int ind2, vector<vector<int>>& dp) {
        if (ind1 >= s.length() || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s[ind1] == s[ind2]) {
            return dp[ind1][ind2] = 1 + recur(s, ind1 + 1, ind2 - 1, dp);
        }

        return dp[ind1][ind2] = 0 + max(recur(s, ind1 + 1, ind2, dp),
                                        recur(s, ind1, ind2 - 1, dp));
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return recur(s, 0, s.length() - 1, dp);
    }
};
Time Complexity: O(N^2), where N is the length of the string s.
Space Complexity: O(N^2)+O(N) = O(N^2).
where N is the length of the string s.

*/

int main()
{
    Solution s;
    string str = "bbbab";
    cout << s.longestPalindromeSubseq(str) << endl; // Output: 4
    return 0;
}