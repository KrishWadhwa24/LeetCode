#include <bits/stdc++.h>
using namespace std;

/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.


Constraints:

1 <= n <= 1690
*/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;

        int po1 = 0, po2 = 0, po3 = 0;
        for (int i = 1; i < n; i++)
        {
            long long int next2 = dp[po1] * 2;
            long long int next3 = dp[po2] * 3;
            long long int next5 = dp[po3] * 5;

            dp[i] = min({next2, next3, next5});

            if (dp[i] == next2)
                po1++;
            if (dp[i] == next3)
                po2++;
            if (dp[i] == next5)
                po3++;
        }
        return dp[n - 1];
    }
};

/*
Time Complexity: O(N), where N is the length of the colors array.
Space Complexity: O(N), where N is the length of the colors array.
*/

/*
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
        return 1;

        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        unordered_set<long long int> seen;
        seen.insert(1);
        pq.push(1);
        long long int cnt = 0;
        while(!pq.empty())
        {
            long long int num = pq.top();
            pq.pop();
            cnt++;

            if(cnt==n)
            return num;

            long long int next2 = num * 2;
            long long int next3 = num * 3;
            long long int next5 = num * 5;

            if (seen.find(next2) == seen.end()) {
                seen.insert(next2);
                pq.push(next2);
            }

            if (seen.find(next3) == seen.end()) {
                seen.insert(next3);
                pq.push(next3);
            }

            if (seen.find(next5) == seen.end()) {
                seen.insert(next5);
                pq.push(next5);
            }
        }
        return 0;
    }
};

Time Complexity: O(NlogN)
Space Complexity: O(N)

*/

int main()
{
    Solution s;
    cout << s.nthUglyNumber(1500) << endl;
    cout << s.nthUglyNumber(1) << endl;
    return 0;
}