#include <bits/stdc++.h>
using namespace std;

/*
You are given two positive integers n and limit.

Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.



Example 1:

Input: n = 5, limit = 2
Output: 3
Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
Example 2:

Input: n = 3, limit = 3
Output: 10
Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).


Constraints:

1 <= n <= 10^6
1 <= limit <= 10^6
*/

typedef long long int ll;
class Solution {
    ll combinations(ll n)
    {
        if(n<0)
        return 0;
        return (1ll*(n+2)*(n+1))/2;
    }
public:
    long long distributeCandies(int n, int limit) {
        ll total = combinations(n);
        ll one = 3*combinations(n-(limit+1));
        ll two = 3*combinations(n-2*(limit+1));

        ll three = combinations(n-3*(limit+1));
        //a1a2a3 = a1+a2+a3-a1a2-a2a3-a1a3+a1a2a3

        ll non_valid = one-two+three;
        return total-non_valid;
    }
};

/*
Time Complexity: O(1) for each test case, since we are using a direct formula to calculate combinations.
Space Complexity: O(1) as we are using a constant amount of space.
*/

/*

typedef long long int ll;
class Solution {
public:
    long long distributeCandies(int n, ll limit) {
        ll ways = 0;
        ll mini = max(0ll,n-2*limit);
        for(ll i =mini;i<=min((ll)n,limit);i++)
        {
            ll N = n-i;
            ll minch2 = max(0ll,N-limit);
            ll maxch2 = min(N,limit);

            ways+=(maxch2-minch2+1);
        }
        return ways;
    }
};

Time Complexity: O(n) in the worst case, but generally much less due to the limits.
Space Complexity: O(1) as we are using a constant amount of space.
*/

int main() {
    Solution s;
    cout << s.distributeCandies(5, 2) << endl; // Output: 3
    cout << s.distributeCandies(3, 3) << endl; // Output: 10
    cout << s.distributeCandies(10, 5) << endl; // Example case
    return 0;
}