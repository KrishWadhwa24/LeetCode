#include <bits/stdc++.h>
using namespace std;

/*
Given an array nums of integers, return how many of them contain an even number of digits.



Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.


Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            while (nums[i])
            {
                cnt++;
                nums[i] /= 10;
            }
            if (cnt % 2 == 0)
                ans++;
        }
        return ans;
    }
};

/*
Time Complexity: O(n * d) where n is the number of elements in the array and d is the number of digits in the largest number.
Space Complexity: O(1) as we are using constant space.
*/

int main()
{
    Solution s;
    vector<int> nums = {12, 345, 2, 6, 7896};
    cout << s.findNumbers(nums) << endl; // Output: 2
    return 0;
}