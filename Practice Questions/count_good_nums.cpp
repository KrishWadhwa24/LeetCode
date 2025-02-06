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

#define MOD 1000000007
class Solution
{
private:
    long long count(long long base, long long n)
    {
        long long result = 1;
        while (n > 0)
        {
            if (n % 2)
            {
                result = (result * base) % MOD;
                n -= 1;
            }
            else
            {
                base = (base * base) % MOD;
                n /= 2;
            }
        }
        return result;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans1 = count(5, even);
        long long ans2 = count(4, odd);

        return (ans1 * ans2) % MOD;
    }
};

int main()
{
    Solution s;
    cout << s.countGoodNumbers(1) << "\n";
    cout << s.countGoodNumbers(4) << "\n";
    cout << s.countGoodNumbers(50) << "\n";
    return 0;
}