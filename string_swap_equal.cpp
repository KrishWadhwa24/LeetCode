#include<bits/stdc++.h>
using namespace std;

/*
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
 

Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
*/


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ch1;
        int ch2;
        int cnt =0;
        int n = s1.length();
        int n2 = s2.length();
        if(n!=n2)
        return false;

        for(int i =0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt>2)
                return false;
                else
                if(cnt==1)
                ch1 = i;
                else
                ch2 = i;

            }
        }
        return (cnt == 0) || (cnt == 2 && s1[ch1] == s2[ch2] && s1[ch2] == s2[ch1]);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main()
{
    Solution s;
    if(s.areAlmostEqual("bank","kanb"))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
    if(s.areAlmostEqual("attack","defend"))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
    if(s.areAlmostEqual("kelb","kelb"))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
    return 0;
}