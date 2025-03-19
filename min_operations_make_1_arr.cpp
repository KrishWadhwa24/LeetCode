#include <bits/stdc++.h>
using namespace std;

/*
You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.



Example 1:

Input: nums = [0,1,1,1,0,0]

Output: 3

Explanation:
We can do the following operations:

Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
Example 2:

Input: nums = [0,1,1,1]

Output: -1

Explanation:
It is impossible to make all elements equal to 1.



Constraints:

3 <= nums.length <= 10^5
0 <= nums[i] <= 1
*/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int r = 0;
        int cnt = 0;

        while (r < n - 2)
        {
            if (nums[r] == 0)
            {
                if (r + 1 >= n || r + 2 >= n)
                    return -1;

                if (r + 2 < n)
                {
                    nums[r] = 1 - nums[r];
                    nums[r + 1] = 1 - nums[r + 1];
                    nums[r + 2] = 1 - nums[r + 2];
                    cnt++;
                }
                else
                {
                    return -1;
                }
            }
            r++;
        }
        if (nums[n - 2] == 0 || nums[n - 1] == 0)
            return -1;

        return cnt;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 0};
    Solution sol;
    cout << sol.minOperations(nums) << endl;
    return 0;
}