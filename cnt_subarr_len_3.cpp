#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.



Example 1:

Input: nums = [1,2,1,4,1]

Output: 1

Explanation:

Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.

Example 2:

Input: nums = [1,1,1]

Output: 0

Explanation:

[1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.



Constraints:

3 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int r = 0;
        int l = 0;
        int cnt = 0;
        while (r < n)
        {
            if (r - l + 1 > 3)
            {
                l++;
            }

            if (r - l + 1 == 3)
            {
                double sum = nums[l] + nums[r];
                double half = nums[l + 1] / 2.0;
                if (sum == half)
                    cnt++;
            }
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
    vector<int> nums = {1, 2, 1, 4, 1};
    cout << s.countSubarrays(nums) << endl; // Output: 1
    return 0;
}