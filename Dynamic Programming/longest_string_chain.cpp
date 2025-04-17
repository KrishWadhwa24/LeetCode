#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.



Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/

class Solution
{
    bool predecesor(string &word1, string &word2)
    {
        if (word2.length() != word1.length() + 1)
            return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < word1.length() && j < word2.length())
        {
            if (word1[i] == word2[j])
            {
                i++;
                j++;
            }
            else
            {
                if (skipped)
                    return false;
                skipped = true;
                j++;
            }
        }

        return true;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        vector<int> dp(n, 1);
        int last = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (predecesor(words[prev], words[i]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                last = i;
            }
        }

        return maxi;
    }
};

/*
Time Complexity: O(n^2 * m)
Space Complexity: O(n)
where n is the length of the input array words and m is the maximum length of a word in the array.
*/

int main()
{
    Solution s;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << s.longestStrChain(words) << endl; // Output: 4
    return 0;
}