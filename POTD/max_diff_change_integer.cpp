#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer num. You will apply the following steps to num two separate times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.



Example 1:

Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
Example 2:

Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8


Constraints:

1 <= num <= 10^8
*/

class Solution
{
public:
    int maxDiff(int num)
    {
        string str = to_string(num);
        int n = str.length();

        string maxi = str;
        string mini = str;

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

        i = 0;
        char ch2;
        char start = str[0];
        while (i < n)
        {
            if (start == '1')
            {
                if (str[i] != '0' && str[i] != '1')
                {
                    ch2 = str[i];
                    break;
                }
                else
                {
                    i++;
                }
            }
            else if (start != '1')
            {
                ch2 = str[i];
                break;
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                maxi[i] = '9';
            }
        }

        if (str[0] == ch2)
        {
            for (int i = 0; i < n; i++)
            {
                if (str[i] == ch2)
                {
                    mini[i] = '1';
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (str[i] == ch2)
                {
                    mini[i] = '0';
                }
            }
        }

        int x1 = stoi(maxi);
        int x2 = stoi(mini);
        return x1 - x2;
    }
};

/*
Time Complexity: O(n), where n is the number of digits in the input number.
Space Complexity: O(n), where n is the number of digits in the input number.
*/

int main()
{
    Solution sol;
    int num = 123456;
    cout << "Max difference: " << sol.maxDiff(num) << endl; // Output: 888
    return 0;
}