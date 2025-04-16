#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
Example 2:

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i], k <= 10^9

*/

class Solution
{
private:
    long long int func(vector<int> &nums, int k, int n)
    {
        int pairs = 0;
        int l = 0;
        int r = 0;
        long long int total = 0;
        long long int cnt = 0;
        unordered_map<long long int, long long int> mpp;
        while (r < n)
        {
            total += mpp[nums[r]];
            mpp[nums[r]]++;

            while (l < n && total >= k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]);
                }
                else
                {
                    total -= (mpp[nums[l]]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    long long countGood(vector<int> &nums, int k)
    {
        long long int n = nums.size();

        long long int total = 1LL * (n * (n + 1)) / 2;
        return total - func(nums, k, n);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is the length of the input array nums.
*/

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int k = 10;
    cout << s.countGood(nums, k) << endl; // Output: 1
    return 0;
}