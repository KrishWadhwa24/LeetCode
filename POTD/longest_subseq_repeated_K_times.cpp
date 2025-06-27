#include<bits/stdc++.h>
using namespace std;

/*
You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

 

Example 1:

example 1
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.
Example 2:

Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".
Example 3:

Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.
 

Constraints:

n == s.length
2 <= n, k <= 2000
2 <= n < k * 8
s consists of lowercase English letters.
*/

class Solution {
private:
    bool isSubsequence(string& s, string& check, int k) {
        int i = 0, j = 0;
        int L = check.length();
        while (i < s.size() && j < L * k) {
            if (s[i] == check[j % L])
                j++;
            i++;
        }
        return j == L * k;
    }

    bool backtrack(string& base, string& curr, int L, int k, string& s,
                   unordered_map<char, int>& count, string& ans) {

        if (curr.size()==L) {
            if (isSubsequence(s, curr, k)) {
                if (curr.size() > ans.size() ||
                    (curr.size() == ans.size() && curr > ans))
                    ans = curr;
                    return true;
            }
            return false;
        }

        for(char ch = 'z';ch>='a';ch--) {
            if (count[ch] > 0) {
                curr.push_back(ch);
                count[ch]--;
                if(backtrack(base, curr, L, k, s, count, ans))
                return true;
                count[ch]++;
                curr.pop_back();
            }
        }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        string base = "";
        unordered_map<char, int> count;
        for (auto&it : freq) {
            if (it.second>= k) {
                int usable = it.second / k;
                count[it.first] = usable;
                base += it.first;
            }
        }
        string curr = "", ans = "";
        for(int i = s.size()/k;i>=0;i--)
        backtrack(base, curr, i, k, s, count, ans);
        return ans;
    }
};

/*

Time Complexity: O(n*(n/k)!)
Space Complexity : O((n/k))

*/

int main() {
    Solution sol;
    string s = "letsleetcode";
    int k = 2;
    cout << sol.longestSubsequenceRepeatedK(s, k) << endl; // Output: "let"
    
    s = "bb";
    k = 2;
    cout << sol.longestSubsequenceRepeatedK(s, k) << endl; // Output: "b"
    
    s = "ab";
    k = 2;
    cout << sol.longestSubsequenceRepeatedK(s, k) << endl; // Output: ""
    
    return 0;
}