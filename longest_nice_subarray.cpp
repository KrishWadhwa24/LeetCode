#include <bits/stdc++.h>
using namespace std;

/*
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.



Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

typedef long long int ll;
class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        int n = nums.size();
        ll sum = 0;
        ll XOR = 0;
        ll maxi = LLONG_MIN;
        while (r < n)
        {
            sum += nums[r];
            XOR = XOR ^ nums[r];

            if (sum != XOR)
            {
                sum -= nums[l];
                XOR ^= nums[l];
                l++;
            }
            if (sum == XOR)
            {
                ll len = (r - l + 1);
                maxi = max(maxi, len);
            }
            r++;
        }
        return maxi;
    }
};

/*
Time Complexity: O(N), where N is the length of the array nums.
Space Complexity: O(1).
*/

/*
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int XOR = 0;
        int maxi = INT_MIN;
        while(r<n)
        {
            sum+=nums[r];
            XOR = XOR^nums[r];

            while(sum!=XOR && l<=r)
            {
                sum = sum - nums[l];
                XOR = XOR^nums[l];
                l++;
            }
            if(sum==XOR)
            {
                int len  = (r-l+1);
                maxi = max(maxi,len);
            }
            r++;
        }
        return maxi;
    }
};

Time Complexity: O(N) + O(N) = O(N), where N is the length of the array nums.
Space Complexity: O(1).
*/

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 8, 48, 10};
    cout << s.longestNiceSubarray(nums) << endl;
    return 0;
}