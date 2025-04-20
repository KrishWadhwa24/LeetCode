#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/

class Solution
{
private:
    void run_manacher(string &s, vector<int> &p, int &maxLen, int &ind)
    {
        int n = s.length();
        int l = 1;
        int r = 1;
        maxLen = 0;
        ind = 0;
        for (int i = 1; i < n; i++)
        {
            if (l + r - i >= 0 && l + r - i < n)
                p[i] = max(0, min(r - i, p[l + r - i]));
            while (i + p[i] < n && i - p[i] >= 0 &&
                   s[i + p[i]] == s[i - p[i]])
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }

            if (p[i] > maxLen)
            {
                maxLen = p[i];
                ind = i;
            }
        }
    }

    string build(string s)
    {
        if (s.empty())
            return "";
        string t;
        t.push_back('#');
        for (auto &ch : s)
        {
            t.push_back(ch);
            t.push_back('#');
        }

        int n = t.length();
        vector<int> p(n, 0);
        int maxLen = 0;
        int ind = 0;
        run_manacher(t, p, maxLen, ind);

        int start = (ind - maxLen + 1) / 2;
        string ans = s.substr(start, maxLen - 1);

        return ans;
    }

public:
    string longestPalindrome(string s) { return build(s); }
};

/*
Time Complexity: O(n) for the Manacher's algorithm.
Space Complexity: O(n) for the auxiliary array p.
*/

/*

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > maxi) {
                    maxi = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > maxi) {
                    maxi = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxi);
    }
};

Time Complexity: O(n^2) for the two nested loops.
Space Complexity: O(1) as we are using only a few extra variables.
*/

int main()
{
    Solution obj;
    string str = "babad";
    cout << obj.longestPalindrome(str) << endl; // Output: "bab" or "aba"
    str = "cbbd";
    cout << obj.longestPalindrome(str) << endl; // Output: "bb"
    return 0;
}