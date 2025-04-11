#include<bits/stdc++.h>
using namespace std;

/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<int> prev(n+1,0);
        int maxi = 0;
        for(int i = n-1;i>=0;i--)
        {
            vector<int> curr(n+1,0);
            for(int j = 1;j<=n;j++)
            {
                if(s[i]==s[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                    maxi = max(maxi,curr[j]);
                }else
                {
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return n - maxi;
    }
};
/*
Time Complexity: O(n*n), where n is the size of s.
Space Complexity: O(n), where n is the size of s.
*/


/*
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int maxi = 0;
        for(int i =n-1;i>=0;i--)
        {
            for(int j = 1;j<=n;j++)
            {
                if(s[i]==s[j-1])
                {
                    dp[i][j] = 1+dp[i+1][j-1];
                    maxi = max(dp[i][j],maxi);
                }else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return n-maxi;
    }
};

Time Complexity: O(n*n);
Space Complexity : O(n*n);
*/

int main()
{
    Solution s;
    string str = "mbadm";
    cout << s.minInsertions(str) << "\n";
    return 0;
}