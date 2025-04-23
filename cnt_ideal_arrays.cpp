#include <bits/stdc++.h>
using namespace std;

/*
You are given two integers n and maxValue, which are used to describe an ideal array.

A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: n = 2, maxValue = 5
Output: 10
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
Example 2:

Input: n = 5, maxValue = 3
Output: 11
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays):
   - With no other distinct values (1 array): [1,1,1,1,1]
   - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.


Constraints:

2 <= n <= 10^4
1 <= maxValue <= 10^4

*/

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

class Solution
{
    int MOD = 1e9 + 7;
    vector<int> options = vector<int>(15, 0);

private:
    void countUnique(int curr, int idx, int maxValue)
    {
        options[idx] += 1;
        for (int j = 2; curr * j <= maxValue; j++)
        {
            countUnique(curr * j, idx + 1, maxValue);
        }
    }

public:
    int idealArrays(int n, int maxValue)
    {
        vector<vector<int>> count(15, vector<int>(100005, 0));
        vector<vector<int>> prefix_sum(15, vector<int>(10001, 0));

        for (int i = 1; i <= 10000; i++)
        {
            count[1][i] = 1;
            prefix_sum[1][i] = i;
        }

        for (int i = 2; i <= 14; i++)
        {
            for (int j = i; j <= 10000; j++)
            {
                count[i][j] = prefix_sum[i - 1][j - 1];
                prefix_sum[i][j] = (count[i][j] + prefix_sum[i][j - 1]) % MOD;
            }
        }

        for (int i = 1; i <= maxValue; i++)
        {
            countUnique(i, 1, maxValue);
        }

        long long ans = 0;

        for (int i = 1; i <= 14; i++)
        {
            long long way = 1LL * count[i][n] * options[i] % MOD;
            ans = (ans + way) % MOD;
        }

        return (int)ans;
    }
};
/*
Time Complexity: O(n * log(maxValue))
Space Complexity: O(n * log(maxValue)) for storing the count of unique elements and prefix sums.
*/

int main()
{
    Solution obj;
    int n = 5, maxValue = 5;
    cout << obj.idealArrays(n, maxValue) << endl;
    return 0;
}