#include <bits/stdc++.h>
using namespace std;

/*

The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums.

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.



Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
Example 2:

Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
Example 3:

Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.


Constraints:

1 <= nums.length <= 12
1 <= nums[i] <= 20
*/

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int result = 0;
        for (int num : nums)
        {
            result |= num;
        }
        return result << (nums.size() - 1);
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
Where N is the number of elements in the array.
*/

/*

class Solution {
    int recur(vector<int>& nums,int val,int ind,vector<vector<int>>& dp)
    {
        if(ind==0)
        return val+(nums[0]^val);

        if(dp[ind][val]!=-1)
        return dp[ind][val];

        int pick = recur(nums,val^nums[ind],ind-1,dp);
        int notpick = recur(nums,val,ind-1,dp);

        return dp[ind][val]= pick+notpick;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int val = 0;
        vector<vector<int>> dp(n,vector<int>(1200,-1));
        return recur(nums,val,n-1,dp);
    }
};

Time Complexity: O(N*1200)
Space Complexity: O(N*1200) + O(N) for recursion stack space.
Where N is the number of elements in the array and 1200 is the maximum possible value of XOR.

*/

int main()
{
    Solution sol;
    vector<int> nums = {1, 3};
    cout << sol.subsetXORSum(nums) << endl; // Output: 6

    nums = {5, 1, 6};
    cout << sol.subsetXORSum(nums) << endl; // Output: 28

    nums = {3, 4, 5, 6, 7, 8};
    cout << sol.subsetXORSum(nums) << endl; // Output: 480

    return 0;
}