#include <bits/stdc++.h>
using namespace std;

/*
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper


Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).


Constraints:

1 <= nums.length <= 10^5
nums.length == n
-10^9 <= nums[i] <= 10^9
-10^9 <= lower <= upper <= 10^9

*/

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long int cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int low =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int upp =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            cnt += (upp - low);
        }
        return cnt;
    }
};

/*
Time Complexity: O(nlogn) for sorting and O(n) for the loop, so overall O(nlogn).
Space Complexity: O(1) as we are using only a few extra variables.
*/

int main()
{
    Solution obj;
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3, upper = 6;
    cout << "Number of fair pairs: " << obj.countFairPairs(nums, lower, upper) << endl; // Output: 6
    return 0;
}