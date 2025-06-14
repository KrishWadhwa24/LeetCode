#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.


Example 1:

Input: num = 11891
Output: 99009
Explanation:
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
Example 2:

Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.


Constraints:

1 <= num <= 10^8
*/

class Solution
{
public:
    int minMaxDifference(int num)
    {
        string str = to_string(num);
        string maxi = str;
        string mini = str;
        int n = str.length();

        int i = 0;
        char ch;
        while (i < n)
        {
            if (str[i] == '9')
                i++;
            else
            {
                ch = str[i];
                break;
            }
        }

        int j = 0;
        char ch2;
        while (j < n)
        {
            if (str[j] == '0')
            {
                j++;
            }
            else
            {
                ch2 = str[j];
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                maxi[i] = '9';
            }

            if (str[i] == ch2)
            {
                mini[i] = '0';
            }
        }
        int x1 = stoi(maxi);
        int x2 = std::stoi(mini);

        return x1 - x2;
    }
};

/*
Time Complexity: O(n), where n is the number of digits in the number.
Space Complexity: O(n), where n is the number of digits in the number
*/

int main()
{
    Solution sol;
    int num = 11891;
    cout << "Max-Min Difference: " << sol.minMaxDifference(num) << endl; // Output: 99009
    return 0;
}