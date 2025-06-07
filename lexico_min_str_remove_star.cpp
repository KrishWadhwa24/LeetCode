#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.



Example 1:

Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"

Output: "abc"

Explanation:

There is no '*' in the string.



Constraints:

1 <= s.length <= 10^5
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.

*/

class Solution
{
    struct custom
    {
        bool operator()(pair<char, int> &a, pair<char, int> &b)
        {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

public:
    string clearStars(string s)
    {
        int n = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int>>, custom> pq;
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                auto it = pq.top();
                pq.pop();

                removed[i] = true;
                removed[it.second] = true;
            }
            else
            {
                pq.push({s[i], i});
            }
        }
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (removed[i] == true)
            {
                continue;
            }

            res += s[i];
        }
        return res;
    }
};

/*
Time Complexity: O(n log n), where n is the length of the string s. This is due to the priority queue operations for each character in the string.
Space Complexity: O(n), where n is the length of the string s. This is due to the priority queue and the removed vector used to track which characters have been removed.
*/

int main()
{
    Solution sol;
    string s = "aaba*";
    cout << sol.clearStars(s) << endl; // Output: "aab"

    s = "abc";
    cout << sol.clearStars(s) << endl; // Output: "abc"

    return 0;
}