#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.



Example 1:

Input: nums = [1,0,1], queries = [[0,2]]

Output: true

Explanation:

For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
The array will become [0, 0, 0], which is a Zero Array.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

Output: false

Explanation:

For i = 0:
Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
The array will become [4, 2, 1, 0].
For i = 1:
Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
The array will become [3, 1, 0, 0], which is not a Zero Array.


Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= li <= ri < nums.length

*/

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> diff(n, 0);

        for (auto &it : queries)
        {
            int l = it[0];
            int r = it[1];

            diff[l] -= 1;
            if (r + 1 < n)
                diff[r + 1] += 1;
        }
        nums[0] = nums[0] + diff[0];
        for (int i = 1; i < n; i++)
        {
            diff[i] = diff[i] + diff[i - 1];
            nums[i] = nums[i] + diff[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return false;
        }
        return true;
    }
};

/*
time complexity: O(n+q)
space complexity: O(n)
*/

void run()
{
    vector<int> nums = {1, 0, 1};
    vector<vector<int>> queries = {{0, 2}};
    Solution s;
    cout << s.isZeroArray(nums, queries) << endl;
}

int main()
{
    run();
    return 0;
}