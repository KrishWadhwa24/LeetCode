#include<bits/stdc++.h>
using namespace std;

/*
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 10^6
*/

class Solution {
    private:
    bool isPrime(int n)
    {
        if(n<2)
        return false;

        if(n==2||n==3)
        return true;

        if(n%2==0)
        return false;

        for(int i = 3;i<=sqrt(n);i+=2)
        {
            if(n%i==0)
            return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        int prev = -1;
        int ans1 = -1;
        int ans2 = -1;

        int mini = INT_MAX;
        for(int i = left;i<=right;i++)
        {
            if(isPrime(i))
            {
                if(prev!=-1)
                {
                    int diff = i - prev;
                    if(diff<mini)
                    {
                        mini = diff;
                        ans1 = prev;
                        ans2 = i;
                    }
                    if(diff<=2)
                    {
                        return {ans1,ans2};
                    }
                }
                prev = i;
            }
        }
        return {ans1,ans2};
    }
};

/*

Time Complexity: O(min(1452,R−L)⋅sqrt(R))
Space Complexity: O(1)

*/

/*

class Solution {
private:
    vector<int> sieve(int n) {
        vector<int> primes, is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++)
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= n; j += i)
                    is_prime[j] = false;
            }
        return primes;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime = sieve(right);
        if (prime.empty() || prime.back() < left)
            return {-1, -1};
        int start_idx =
            lower_bound(prime.begin(), prime.end(), left) - prime.begin();
        int end_idx =
            lower_bound(prime.begin(), prime.end(), right) - prime.begin();
        int min_diff = INT_MAX;
        int ans1 = -1, ans2 = -1;
        if (prime[end_idx] == right) {
            for (int i = start_idx; i <= end_idx - 1; i++) {
                int d = prime[i + 1] - prime[i];
                if (d < min_diff) {
                    min_diff = d;
                    ans1 = prime[i];
                    ans2 = prime[i + 1];
                }
                if (min_diff <= 2)
                    break;
            }
        } else {
            for (int i = start_idx; i < end_idx - 1; i++) {
                int d = prime[i + 1] - prime[i];
                if (d < min_diff) {
                    min_diff = d;
                    ans1 = prime[i];
                    ans2 = prime[i + 1];
                }
                if (min_diff <= 2)
                    break;
            }
        }

        return {ans1, ans2};
    }
};

Time Complexity: O(NloglogN)
Space Complexity: O(N)

*/

int main()
{
    Solution s;
    vector<int> ans = s.closestPrimes(10,19);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}