#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.



Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= target <= 10^6

*/

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        int n = nums.size();
        long long cnt = 0;

        int l = 0, r = n - 1;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; i++)
            pows[i] = pows[i - 1] * 2 % mod;

        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
            {
                cnt = (cnt + pows[r - l]) % mod;
                l++;
            }
            else
            {
                r--;
            }
        }

        return cnt;
    }
};

/*
Time Complexity: O(n log n) due to sorting the array.
Space Complexity: O(n) for the power array.
*/

int main()
{
    Solution sol;
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    cout << sol.numSubseq(nums, target) << endl; // Output: 4

    nums = {3, 3, 6, 8};
    target = 10;
    cout << sol.numSubseq(nums, target) << endl; // Output: 6

    nums = {2, 3, 3, 4, 6, 7};
    target = 12;
    cout << sol.numSubseq(nums, target) << endl; // Output: 61

    return 0;
}