#include <bits/stdc++.h>
using namespace std;

/*

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

*/

// Optimal Solution
class Solution
{
public:
    bool checkValidString(string s)
    {
        int open = 0;
        int closed = 0;
        int length = s.length() - 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '*')
                open++;
            else
                open--;

            if (s[length - i] == ')' || s[length - i] == '*')
                closed++;
            else
                closed--;

            if (open < 0 || closed < 0)
                return false;
        }
        return true;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

//Better Solution

/*
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> free;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='*')
            free.push(i);
            else
            if(s[i]=='(')
            {
                open.push(i);
            }else
            if(s[i]==')')
            {
                if(!open.empty())
                open.pop();
                else
                if(!free.empty())
                free.pop();
                else
                return false;
            }
        }
        while(!open.empty() && !free.empty())
        {
            if(open.top()<free.top())
            {
                open.pop();
                free.pop();
            }else
            return false;
        }
        return open.empty();
    }
};

*/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

int main()
{
    string s = "(*))";
    Solution obj;
    if (obj.checkValidString(s))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}