#include <bits/stdc++.h>
using namespace std;

/*
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int a = 0;
        int b = 1;
        int c = 1;
        int curr = 0;
        for (int i = 3; i <= n; i++)
        {
            curr = a + b + c;
            a = b;
            b = c;
            c = curr;
        }
        return curr;
    }
};

/*
Time Complexity: O(n), where n is the input number.
Space Complexity: O(1), as we are using only a constant amount of space.
*/

/*

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        if (n < 3) {
            return dp[n - 1];
        }
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

/*
Time Complexity: O(n), where n is the input number.
Space Complexity: O(n), as we are using an array of size n+1 to store the results.
*/

/*


class Solution {
private:
    int recur(int n, vector<int>& dp) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = recur(n - 1, dp) + recur(n - 2, dp) + recur(n - 3, dp);
    }

public:
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return recur(n, dp);
    }
};

Time Complexity: O(n), where n is the input number.
Space Complexity: O(n), as we are using an array of size n+1 to store the results.
Space Complexity: O(n), as we are using a stack space of O(n) for recursion.

*/

int main()
{
    Solution obj;
    int n = 27;
    cout << obj.tribonacci(n) << endl;
    return 0;
}