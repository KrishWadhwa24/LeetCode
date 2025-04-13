#include <bits/stdc++.h>
using namespace std;

/*
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.



Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303


Constraints:

1 <= n <= 10^15

*/

const int mod = 1e9 + 7;

class Solution
{
private:
    long long power(long long num, long long p)
    {
        long long ans = 1;
        while (p > 0)
        {
            if (p % 2 == 1)
            {
                ans = (ans * num) % mod;
            }
            num = (num * num) % mod;
            p /= 2;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long even = power(5, even_positions);
        long long odd = power(4, odd_positions);
        return (even * odd) % mod;
    }
};

/*
Time Complexity: O(log n) for power function.
Space Complexity: O(1) for storing variables.
*/

int main()
{
    Solution obj;
    long long n = 50;
    cout << obj.countGoodNumbers(n) << endl;
    return 0;
}