#include <bits/stdc++.h>
using namespace std;

/*

You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.



Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.


Constraints:

1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.

*/

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        stack<int> st;
        string str;
        for (int i = 0; i <= pattern.size(); i++)
        {
            st.push(i + 1);

            if (i == pattern.size() || pattern[i] == 'I')
            {
                while (!st.empty())
                {
                    str += to_string(st.top());
                    st.pop();
                }
            }
        }
        return str;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*
Approach: Recursion

class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";

        // Start building the sequence by calling the helper function
        buildSequence(0, 0, pattern, result);
        // Reverse the final result
        reverse(result.begin(), result.end());
        return result;
    }

    // Recursively build the sequence
    int buildSequence(int currentIndex, int currentCount, string pattern,
                      string& result) {
        if (currentIndex != pattern.size()) {
            if (pattern[currentIndex] == 'I')
                // If 'I', increment the count and move to the next index
                buildSequence(currentIndex + 1, currentIndex + 1, pattern,
                              result);
            else
                // If 'D', keep the count and move to the next index
                currentCount = buildSequence(currentIndex + 1, currentCount,
                                             pattern, result);
        }

        result += to_string(currentCount + 1);
        // Return the next count for the sequence
        return currentCount + 1;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)

*/

/*
Approach: Backtracking
class Solution
{
private:
    bool backtrack(string &pattern, unordered_set<int> &used, string &str, int index, int n)
    {
        if (index == n)
        {
            return true;
        }

        char ch = pattern[index];
        int last = str.back() - '0';

        if (ch == 'I')
        {
            for (int i = last + 1; i <= 9; i++)
            {
                if (used.find(i) == used.end())
                {
                    str.push_back(i + '0');
                    used.insert(i);
                    if (backtrack(pattern, used, str, index + 1, n))
                        return true;
                    str.pop_back();
                    used.erase(i);
                }
            }
        }
        else
        {
            for (int i = 1; i < last; i++)
            {
                if (used.find(i) == used.end())
                {
                    str.push_back(i + '0');
                    used.insert(i);
                    if (backtrack(pattern, used, str, index + 1, n))
                        return true;
                    str.pop_back();
                    used.erase(i);
                }
            }
        }

        return false;
    }

public:
    string smallestNumber(string pattern)
    {
        int n = pattern.length();

        for (int i = 1; i <= 9; i++)
        {
            unordered_set<int> used;
            string str = "";
            str.push_back(i + '0');
            used.insert(i);

            if (backtrack(pattern, used, str, 0, n))
                return str;
        }

        return "";
    }
};

Time Complexity: O(9 * 8 * 7 * ... * (9 - n + 1)) = O((9 - n + 1)!) = O(n!)
Space Complexity: O(n)
*/

int main()
{
    Solution s;
    cout << s.smallestNumber("IIIDIDDD") << endl;
    cout << s.smallestNumber("DDD") << endl;
    return 0;
}