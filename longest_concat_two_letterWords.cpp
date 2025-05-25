#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.



Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".


Constraints:

1 <= words.length <= 10^5
words[i].length == 2
words[i] consists of lowercase English letters.
*/

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mpp;
        int maxi = 0;
        int len = 0;
        for (auto &it : words)
        {
            mpp[it]++;
        }
        bool middle = false;
        for (auto &it : mpp)
        {
            string str = it.first;
            int cnt = it.second;

            string rev = str;
            reverse(rev.begin(), rev.end());
            if (str == rev)
            {
                len += (mpp[str] / 2) * 4;
                if (cnt % 2 != 0)
                {
                    middle = true;
                }
            }
            else if (mpp.find(rev) != mpp.end())
            {
                len += min(mpp[str], mpp[rev]) * 4;
                mpp[str] = 0;
                mpp[rev] = 0;
            }
        }

        return len + maxi + ((middle == true) ? 2 : 0);
    }
};
/*
Time Complexity: O(n), where n is the number of words in the input array.
Space Complexity: O(n), for storing the frequency of each word in the unordered_map.
*/

int main()
{
    Solution sol;
    vector<string> words = {"lc", "cl", "gg"};
    int result = sol.longestPalindrome(words);
    cout << result << endl; // Output: 6
    return 0;
}