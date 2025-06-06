#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.



Example 1:

Input: s = "zza"
Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".
Example 2:

Input: s = "bac"
Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba".
Perform second operation twice p="ab", s="c", t="".
Perform first operation p="ab", s="", t="c".
Perform second operation p="abc", s="", t="".
Example 3:

Input: s = "bdda"
Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".


Constraints:

1 <= s.length <= 10^5
s consists of only English lowercase letters.

*/

class Solution
{
private:
    char mini(vector<int> &mpp)
    {
        for (int i = 0; i < 26; i++)
        {
            if (mpp[i] > 0)
                return i + 'a';
        }
        return 'z';
    }

public:
    string robotWithString(string s)
    {
        int n = s.length();
        vector<int> mpp(26, 0);

        for (auto &it : s)
        {
            mpp[it - 'a']++;
        }
        string t = "";
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            t.push_back(s[i]);
            mpp[s[i] - 'a']--;

            while (!t.empty() && t.back() <= mini(mpp))
            {
                ans.push_back(t.back());
                t.pop_back();
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main()
{
    Solution s;
    string str = "bdda";
    cout << s.robotWithString(str) << endl; // Output: "addb"

    str = "bac";
    cout << s.robotWithString(str) << endl; // Output: "abc"

    str = "zza";
    cout << s.robotWithString(str) << endl; // Output: "azz"

    str = "cba";
    cout << s.robotWithString(str) << endl; // Output: "abc"

    str = "abacaba";
    cout << s.robotWithString(str) << endl; // Output: "aaabbbcc"

    return 0;
}