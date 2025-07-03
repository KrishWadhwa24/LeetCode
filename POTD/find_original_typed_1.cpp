#include<bits/stdc++.h>
using namespace std;

/*
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: word = "aabbccdd", k = 7

Output: 5

Explanation:

The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".

Example 2:

Input: word = "aabbccdd", k = 8

Output: 1

Explanation:

The only possible string is "aabbccdd".

Example 3:

Input: word = "aaabbb", k = 3

Output: 8

 

Constraints:

1 <= word.length <= 5 * 10^5
word consists only of lowercase English letters.
1 <= k <= 2000
*/

class Solution {
    const int mod = 1e9 + 7;

public:
    int possibleStringCount(string word, int k) {
        int n = word.length();
        int cnt = 1;
        vector<int> freq;

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);
        long long total = 1;
        for (auto& it : freq) {
            total = (total * it) % mod;
        }
        if (freq.size() >= k) {
            return (int)(total % mod);
        }
        int m = freq.size();
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

        for (int j = 0; j < k; j++) {
            dp[m][j] = 1;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            vector<int> prefix(k+1,0);
            prefix[0] = 0;
            for(int h = 1;h<=k;h++)
            {
                prefix[h] = (dp[i+1][h-1]+prefix[h-1])%mod;
            }
            for (int cnt = k - 1; cnt >= 0; cnt--) {
                int l = cnt+1;
                int r = cnt+freq[i];
                if(r+1>k)
                {
                    r = k-1;
                }
                if(l<=r)
                dp[i][cnt] = (prefix[r+1]-prefix[l]+mod)%mod;
            }
        }

        return (total - dp[0][0] + mod) % mod;
    }
};
/*
Time Complexity: O(n*k)
Space Complexity: O(n*k)
*/

/*

class Solution {
    const int mod = 1e9 + 7;

public:
    int possibleStringCount(string word, int k) {
        int n = word.length();
        int cnt = 1;
        vector<int> freq;

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);
        long long total = 1;
        for (auto& it : freq) {
            total = (total * it) % mod;
        }
        if (freq.size() >= k) {
            return (int)(total % mod);
        }
        int m = freq.size();
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

        for (int j = 0; j < k; j++) {
            dp[m][j] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int cnt = k - 1; cnt >= 0; cnt--) {
                long long res = 0;
                for (int take = 1; take <= freq[i]; take++) {
                    if (take + cnt < k) {
                        res = (res + dp[i + 1][cnt + take]) % mod;
                    } else {
                        break;
                    }
                }
                dp[i][cnt] = res;
            }
        }

        return (total - dp[0][0] + mod) % mod;
    }
};

Time Complexity: O(n*k)
Space Complexity: O(n*k)

*/


/*


class Solution {
    const int mod = 1e9 + 7;
private:
    int solve(string& word, int k, int idx, int cnt, vector<int>& freq,vector<vector<int>>& dp) {
        if (idx == freq.size()) {
            if (cnt < k)
                return 1;
            else
                return 0;
        }

        if(dp[idx][cnt]!=-1)
        return dp[idx][cnt];

        int result = 0;
        for (int take = 1; take <= freq[idx]; take++) {
            if (take + cnt < k) {
                result = (result+solve(word, k, idx + 1, cnt + take, freq,dp))%mod;
            } else
                break;
        }
        return dp[idx][cnt] = result%mod;
    }

public:
    int possibleStringCount(string word, int k) {
        int n = word.length();
        int cnt = 1;
        vector<int> freq;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1])
                cnt++;
            else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);
        long long int total = 1;
        for (auto& it : freq) {
            total = (total*it)%mod;
        }

        if (freq.size() >= k)
            return (int)(total%mod);
        else{
            vector<vector<int>> dp(freq.size()+1,vector<int>(k+1,-1));
            return (total-solve(word,k,0,0,freq,dp)+mod)%mod;
        }
    }
};

Time Complexity: O(n*k)
Space Complexity: O(n*k)

*/

int main() {
    Solution sol;
    string word = "aabbccdd";
    int k = 7;
    cout << sol.possibleStringCount(word, k) << endl; // Output: 5
    return 0;
}