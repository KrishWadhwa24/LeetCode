#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.


Constraints:

2 <= nums.length <= 10^5
1 <= nums[i], minK, maxK <= 10^6

*/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int r = 0;
        int k = -1;
        int n = nums.size();
        int minpos = -1;
        int maxpos = -1;
        long long int cnt = 0;
        while (r < n)
        {
            if (nums[r] > maxK || nums[r] < minK)
            {
                k = r;
            }
            if (nums[r] == minK)
            {
                minpos = r;
            }

            if (nums[r] == maxK)
            {
                maxpos = r;
            }

            long long int l = min(minpos, maxpos);

            if (l > k)
                cnt += (l - k);

            r++;
        }
        return cnt;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1;
    int maxK = 5;
    cout << s.countSubarrays(nums, minK, maxK) << endl; // Output: 2
    return 0;
}