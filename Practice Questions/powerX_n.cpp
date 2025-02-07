#include <bits/stdc++.h>
using namespace std;

/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).



Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= xn <= 10^4
*/

typedef long long int ll;
class Solution
{
private:
    void power(double x, ll nn, double &ans)
    {
        if (nn == 0)
            return;

        if (nn % 2)
        {
            ans = ans * x;
            nn -= 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
        power(x, nn, ans);
    }

public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        ll nn = n;
        if (nn < 0)
            nn = -1 * nn;

        power(x, nn, ans);
        if (n < 0)
            ans = 1 / ans;

        return ans;
    }
};
/*
Time Complexity: O(log(n))
Space Complexity: O(1)
*/

int main()
{
    Solution s;
    cout << s.myPow(2.00000, 10) << endl;
    cout << s.myPow(2.10000, 3) << endl;
    cout << s.myPow(2.00000, -2) << endl;
    return 0;
}