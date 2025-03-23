#include <bits/stdc++.h>
using namespace std;

/*

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

*/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int far = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > far)
                return false;
            far = max(far, i + nums[i]);
            if (i + nums[i] >= n - 1)
                return true;
        }
        return false;
    }
};

/*
Time Complexity: O(N), where N is the number of elements in the array.
Space Complexity: O(1)
*/

/*

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<long long> vis(n,0);
        vis[0] = true;
        for(int i =0;i<n;i++)
        {

            if(vis[i]==0)
            return false;

            if(i+nums[i]>=n-1)
            return true;


            for(int j=i+1;j<=min(n-1,i+nums[i]);j++)
            {
                vis[j] = 1;
            }
        }
        return vis[n-1]==1;
    }
};

Time Complexity: O(N^2), where N is the number of elements in the array.
Space Complexity: O(N)
*/

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.canJump(nums) << endl;
    return 0;
}