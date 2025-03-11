#include <bits/stdc++.h>
using namespace std;

/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
Example 3:

Input: s = "abc"
Output: 1


Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        vector<int> lastSeen(3, -1);
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                cnt = cnt + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
            }
        }
        return cnt;
    }
};

/*
Time Complexity: O(N), where N is the length of the string s.
Space Complexity: O(1).
*/

/*
Brute Force

class Solution {
public:
    int func(string s, int k) {
        map<char, int> mpp;
        int l = 0, r = 0;
        int cnt = 0;
        while (r < s.length()) {
            mpp[s[r]]++;
            
            // Shrink the window if the size of the map exceeds `k`
            while (mpp.size() > k) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) {
                    mpp.erase(s[l]);
                }
                l++;
            }
            
            // Count valid substrings ending at `r`
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    
    int numberOfSubstrings(string s) {
        return func(s, 3) - func(s, 2);
    }
};

Time Complexity: O(N), where N is the length of the string s.
Space Complexity: O(3).

*/

int main()
{
    Solution s;
    string s1 = "abcabc";
    string s2 = "aaacb";
    string s3 = "abc";
    cout << s.numberOfSubstrings(s1) << endl;
    cout << s.numberOfSubstrings(s2) << endl;
    cout << s.numberOfSubstrings(s3) << endl;
    return 0;
}