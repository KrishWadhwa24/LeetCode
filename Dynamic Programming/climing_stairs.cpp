#include <bits/stdc++.h>
using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

class Solution
{
public:
    int climbStairs(int n)
    {

        if (n <= 1)
            return 1;
        int prev1 = 1;
        int prev2 = 1;
        int curr = 0;
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
class Solution {
private:
    int recurse(int n,vector<int>& dp) {
        if (n == 0) {
            return 1;
        } else if (n == 1)
            return 1;
        else if (n < 0)
            return 0;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n] = recurse(n-1,dp)+recurse(n-2,dp);

    }

public:
    int climbStairs(int n) {
        int cnt = 0;
        vector<int> dp(n+1,-1);
        cnt = recurse(n,dp);
        return cnt;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
*/

int main()
{
    Solution s;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;
    cout << s.climbStairs(4) << endl;
    cout << s.climbStairs(5) << endl;
    cout << s.climbStairs(6) << endl;
    cout << s.climbStairs(7) << endl;
    cout << s.climbStairs(8) << endl;
    cout << s.climbStairs(9) << endl;
    cout << s.climbStairs(10) << endl;
    cout << s.climbStairs(11) << endl;
    cout << s.climbStairs(12) << endl;
    cout << s.climbStairs(13) << endl;
    cout << s.climbStairs(14) << endl;
    cout << s.climbStairs(15) << endl;
    cout << s.climbStairs(16) << endl;
    cout << s.climbStairs(17) << endl;
    cout << s.climbStairs(18) << endl;
    cout << s.climbStairs(19) << endl;
    cout << s.climbStairs(20) << endl;
    cout << s.climbStairs(21) << endl;
    cout << s.climbStairs(22) << endl;
    return 0;
}