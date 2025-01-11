#include <bits/stdc++.h>
using namespace std;
/*
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.



Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.


Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= 10^5

*/

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int arr[26];
        memset(arr, 0, sizeof arr);
        int n = s.length();
        if (n == k)
            return true;
        else if (n < k)
            return false;
        for (auto it : s)
        {
            arr[it - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            cnt += arr[i] & 1;
        }
        if (cnt > k)
            return false;
        else
            return true;
    }
};

int main()
{
    string s = "annabelle";
    int k = 2;
    Solution obj;
    if(obj.canConstruct(s,k))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    return 0;
}