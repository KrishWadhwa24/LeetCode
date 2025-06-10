#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.



Example 1:

Input: s = "aaaaabbc"

Output: 3

Explanation:

The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.
Example 2:

Input: s = "abcabcab"

Output: 1

Explanation:

The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.


Constraints:

3 <= s.length <= 100
s consists only of lowercase English letters.
s contains at least one character with an odd frequency and one with an even frequency.

*/

class Solution
{
public:
    int maxDifference(string s)
    {
        unordered_map<char, int> mpp;
        int maxi1 = 0, maxi2 = INT_MAX;

        for (auto &it : s)
        {
            mpp[it]++;
        }

        for (auto &it : mpp)
        {
            int freq = it.second;
            if (freq % 2 != 0)
            {
                maxi1 = max(maxi1, freq);
            }
            else
            {
                maxi2 = min(maxi2, freq);
            }
        }

        return maxi1 - maxi2;
    }
};

/*
Time Complexity: O(n), where n is the length of the string s. We traverse the string once to count frequencies and then iterate through the frequency map.
Space Complexity: O(1), since the frequency map will have at most 26 entries (for each lowercase English letter).
*/

int main()
{
    Solution sol;
    string s = "aaaaabbc";
    cout << sol.maxDifference(s) << endl; // Output: 3

    s = "abcabcab";
    cout << sol.maxDifference(s) << endl; // Output: 1

    return 0;
}