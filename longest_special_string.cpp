/*
You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumLength(string s)
    {
        int start = 0;
        unordered_map<string, int> mpp;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == s.length() - 1 || s[i] != s[i + 1])
            {
                int len = i - start + 1;
                string str = s.substr(start, len);
                start = i + 1;
                mpp[str]++;
                if (len >= 2)
                {
                    mpp[str.substr(0, len - 1)] += 2;
                }
                if (len >= 3)
                {
                    mpp[str.substr(0, len - 2)] += 3;
                }
            }
        }
        int res = -1;
        for (auto it : mpp)
        {
            if (it.second >= 3)
                res = max(res, (int)it.first.length());
        }
        return res;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N^2)

// Brute Force

// class TrieNode {
// public:
//     unordered_map<char, TrieNode*> children;
//     int count;

//     TrieNode() {
//         count = 0;
//     }
// };

// class Trie {
// private:
//     TrieNode* root;

// public:
//     Trie() {
//         root = new TrieNode();
//     }

//     void insert(const string& s) {
//         TrieNode* node = root;
//         for (char c : s) {
//             if (!node->children[c]) {
//                 node->children[c] = new TrieNode();
//             }
//             node = node->children[c];
//             node->count++;
//         }
//     }
//     int findLongestSpecialSubstring() {
//         return dfs(root, "");
//     }

// private:
//     int dfs(TrieNode* node, const string& current) {
//         int maxLength = -1;
//         if (node->count >= 3 && isSpecial(current)) {
//             maxLength = current.length();
//         }
//         for (auto& [c, child] : node->children) {
//             maxLength = max(maxLength, dfs(child, current + c));
//         }
//         return maxLength;
//     }

//     bool isSpecial(const string& s) {
//         return !s.empty() && all_of(s.begin(), s.end(), [s](char c) { return c == s[0]; });
//     }
// };

// class Solution {
// public:
//     int maximumLength(string s) {
//        Trie trie;

//     for (int i = 0; i < s.length(); i++) {
//         trie.insert(s.substr(i));
//     }
//     return trie.findLongestSpecialSubstring();
//     }
// };

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

int main()
{
    Solution s;
    cout << s.maximumLength("ababccc") << endl;
    cout << s.maximumLength("ababcccd") << endl;
    cout << s.maximumLength("aabbbcc") << endl;
    cout << s.maximumLength("ababccccc") << endl;
    cout << s.maximumLength("ababbbbbbbbbbcccccc") << endl;
    cout << s.maximumLength("ababccccccc") << endl;
    return 0;
}