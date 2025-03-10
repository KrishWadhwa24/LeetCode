#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3^x.



Example 1:

Input: n = 12
Output: true
Explanation: 12 = 3^1 + 3^2
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 3^0 + 3^2 + 3^4
Example 3:

Input: n = 21
Output: false


Constraints:

1 <= n <= 10^7
*/

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {
            int rem = n % 3;
            if (rem == 2)
                return false;

            n /= 3;
        }
        return true;
    }
};

/*
Time Complexity: O(log3(n))
Space Complexity: O(1)
*/

int main()
{
    int n = 12;
    Solution s;
    cout << s.checkPowersOfThree(n) << endl;
    return 0;
}