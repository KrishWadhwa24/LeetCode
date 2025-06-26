#include<bits/stdc++.h>
using namespace std;

/*
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 

Example 1:

Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
Example 2:

Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= k <= 10^9
*/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int idx = 0;
        int cnt = 0;
        int val =0;
        for(int i = n-1;i>=0;i--)
        {
            int bit = s[i]-'0';
            if(bit==1)
            {
                if(val+(1<<idx)<=k)
                {
                    val += (1 << idx); 
                    idx++;
                    cnt++;
                }
            }else
            {
                idx++;
                cnt++;
            }
        }
        return cnt;


    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*

class Solution {
private:
    int recur(const string& s, int k, int ind, int idx, int val,vector<int>& dp) {
        if (ind < 0)
            return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        int pick = INT_MIN;
        int bit = s[ind] - '0';

        if (val + (bit * pow(2, idx)) <= k) {
            int new_val = val + (bit * pow(2, idx));
            pick = 1 + recur(s, k, ind - 1, idx + 1, new_val,dp);
        }

        int not_pick = recur(s, k, ind - 1, idx, val,dp);

        return dp[ind]=max(pick, not_pick);
    }

public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        vector<int> dp(n,-1);
        return recur(s, k, n - 1, 0, 0,dp);
    }
};

Time Complexity: O(n*logK)
Space Complexity: O(n)

*/

int main() {
    Solution sol;
    string s = "1001010";
    int k = 5;
    int result = sol.longestSubsequence(s, k);
    
    cout << result << endl; // Output: 5

    s = "00101001";
    k = 1;
    result = sol.longestSubsequence(s, k);
    
    cout << result << endl; // Output: 6

    return 0;
}