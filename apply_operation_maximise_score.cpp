#include <bits/stdc++.h>
using namespace std;

/*
You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.



Example 1:

Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.
Example 2:

Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations:
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.


Constraints:

1 <= nums.length == n <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= min(n * (n + 1) / 2, 10^9)

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
private:
    const ll MOD = 1e9 + 7;

    void sieve(vector<bool> &isPrime, int limit)
    {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= limit; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= limit && j > 0;
                     j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }

    ll modPow(ll base, ll exp, ll mod)
    {
        ll result = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    int maximumScore(vector<int> &nums, int k)
    {
        ll K = k;
        int n = nums.size();
        int maxi = 0;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());

        vector<bool> prime(maxi + 1, true);
        sieve(prime, maxi);
        vector<int> primeCount(n, 0);

        for (int i = 0; i < n; i++)
        {
            int num = nums[i], cnt = 0;
            for (int j = 2; j * j <= num; j++)
            {
                if (prime[j] && num % j == 0)
                {
                    cnt++;
                    while (num % j == 0)
                    {
                        num /= j;
                    }
                }
            }
            if (num > 1)
                cnt++;
            primeCount[i] = cnt;
        }

        vector<pair<int, int>> range(n, {-1, n});
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && primeCount[i] > primeCount[st.top()])
            {
                range[st.top()].second = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && primeCount[i] >= primeCount[st.top()])
            {
                range[st.top()].first = i;
                st.pop();
            }
            st.push(i);
        }

        vector<ll> store(n);
        for (int i = 0; i < n; i++)
        {
            store[i] = 1LL * (i - range[i].first) * (range[i].second - i);
        }

        ll ans = 1;
        for (int i = 0; i < n && K > 0; i++)
        {
            auto it = vec[i];
            ll take = min(K, store[it.second]);
            ans = (ans * modPow(it.first, take, MOD)) % MOD;
            K -= take;
        }

        return ans;
    }
};

/*
Time Complexity: O(nlogn + n + n + nloglogn) = O(nlogn)
Space Complexity: O(n + n) = O(n)
*/

int main()
{
    Solution s;
    vector<int> nums = {8, 3, 9, 3, 8};
    int k = 2;
    cout << s.maximumScore(nums, k) << endl; // Output: 81
    return 0;
}
