#include <bits/stdc++.h>
using namespace std;

/*
You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.



Example 1:

Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".
Example 2:

Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
Example 3:

Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".


Constraints:

1 <= s1.length, s2.length, baseStr <= 1000
s1.length == s2.length
s1, s2, and baseStr consist of lowercase English letters.
*/

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length();

        vector<vector<int>> adj(26);
        for (int i = 0; i < n; i++)
        {
            adj[s1[i] - 'a'].push_back(s2[i] - 'a');
            adj[s2[i] - 'a'].push_back(s1[i] - 'a');
        }
        int len = baseStr.length();
        string str = "";
        for (int i = 0; i < len; i++)
        {
            vector<int> vis(26, 0);
            char ch = baseStr[i];

            queue<int> q;
            q.push(baseStr[i] - 'a');
            vis[baseStr[i] - 'a'] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto it : adj[node])
                {
                    if (vis[it] == 0)
                    {
                        vis[it] = 1;
                        ch = min(ch, char(it + 'a'));

                        q.push(it);
                    }
                }
            }

            str += ch;
        }
        return str;
    }
};

/*
Time Complexity: O(n * m), where n is the length of s1 and s2, and m is the length of baseStr.
Space Complexity: O(n), where n is the number of unique characters in s1 and s2 (which is at most 26 for lowercase English letters).
*/

int main()
{
    Solution sol;
    string s1 = "parker", s2 = "morris", baseStr = "parser";
    cout << sol.smallestEquivalentString(s1, s2, baseStr) << endl; // Output: "makkek"

    s1 = "hello", s2 = "world", baseStr = "hold";
    cout << sol.smallestEquivalentString(s1, s2, baseStr) << endl; // Output: "hdld"

    s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    cout << sol.smallestEquivalentString(s1, s2, baseStr) << endl; // Output: "aauaaaaada"

    return 0;
}