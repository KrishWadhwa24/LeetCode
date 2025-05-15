#include <bits/stdc++.h>
using namespace std;

/*
You are given a string array words and a binary array groups both of length n, where words[i] is associated with groups[i].

Your task is to select the longest alternating subsequence from words. A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements in the binary array groups differ. Essentially, you are to choose strings such that adjacent elements have non-matching corresponding bits in the groups array.

Formally, you need to find the longest subsequence of an array of indices [0, 1, ..., n - 1] denoted as [i0, i1, ..., ik-1], such that groups[ij] != groups[ij+1] for each 0 <= j < k - 1 and then find the words corresponding to these indices.

Return the selected subsequence. If there are multiple answers, return any of them.

Note: The elements in words are distinct.



Example 1:

Input: words = ["e","a","b"], groups = [0,0,1]

Output: ["e","b"]

Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2]. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,0,1,1]

Output: ["a","b","c"]

Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.



Constraints:

1 <= n == words.length == groups.length <= 100
1 <= words[i].length <= 10
groups[i] is either 0 or 1.
words consists of distinct strings.
words[i] consists of lowercase English letters.
*/

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = groups.size();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || groups[i] != groups[i - 1])
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        int maxi = 0;
        int lastIndex = -1;
        for(int i =0;i<n;i++)
        {
            hash[i] = i;
            for(int j = 0;j<i;j++)
            {
                if(groups[j]!=groups[i] && 1+dp[j]>dp[i])
                {
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<string> ans;
        ans.push_back(words[lastIndex]);

        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans.push_back(words[lastIndex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

int main()
{
    Solution sol;
    vector<string> words = {"e", "a", "b"};
    vector<int> groups = {0, 0, 1};
    vector<string> result = sol.getLongestSubsequence(words, groups);
    for (const string &word : result)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}