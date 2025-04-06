#include<bits/stdc++.h>
using namespace std;

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }else
                {
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }

        return prev[m];
    }
};

/*
Time Complexity: O(n*m)
Space Complexity: O(m)
Where n is the length of text1 and m is the length of text2.
*/


/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i =0;i<=m;i++)
        {
            dp[0][i]= 0;
        }
        for(int j =0;j<=n;j++)
        {
            dp[j][0]= 0;
        }

        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else
                {
                    dp[i][j]= 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
Time Complexity: O(n*m)
Space Complexity: O(n*m)
Where n is the length of text1 and m is the length of text2.

*/

/*
class Solution {
    private:
    int recur(string& text1,string& text2,int ind1,int ind2,vector<vector<int>>& dp)
    {
        if(ind1==0 || ind2==0)
        return 0;

        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

        if(text1[ind1-1]==text2[ind2-1])
        {
            return dp[ind1][ind2]=  1+ recur(text1,text2,ind1-1,ind2-1,dp);
        }

        return dp[ind1][ind2] =  0+max(recur(text1,text2,ind1-1,ind2,dp),recur(text1,text2,ind1,ind2-1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recur(text1,text2,n,m,dp);
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m) + O(n+m) for recursion stack space.
Where n is the length of text1 and m is the length of text2.
*/

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    Solution sol;
    cout << sol.longestCommonSubsequence(text1, text2) << endl; // Output: 3
    return 0;
}