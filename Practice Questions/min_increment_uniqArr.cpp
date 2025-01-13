#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
Example 2:

Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown that it is impossible for the array to have all unique values with 5 or less moves.


Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5

*/
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxi < nums[i])
                maxi = nums[i];
        }
        vector<int> freq(n + maxi, 0);
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] <= 1)
                continue;
            int duplicates = freq[i] - 1;
            freq[i + 1] += duplicates;
            freq[i] = 1;
            cnt += duplicates;
        }
        return cnt;
    }
};

/*
Time complexity: O(n)+O(n)+O(n) = O(n)
Space complexity: O(n+maxi)
*/

/*
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int move =0;
        unordered_map<int,int> mpp;
        for(int i =0;i<nums.size();i++)
        {
            auto it = mpp.find(nums[i]);
            if(it==mpp.end())
            {
                mpp[nums[i]]=i;
            }else
            {
                move = move + (i-it->second);
                mpp[nums[i]+(i-it->second)]=i;
            }
        }
        return move;
    }
};


Time complexity: O(nlogn)
Space complexity: O(n)

*/

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2};
    vector<int> nums2 = {3, 2, 1, 2, 1, 7};

    cout << "Minimum moves for nums1: " << sol.minIncrementForUnique(nums1) << endl;
    cout << "Minimum moves for nums2: " << sol.minIncrementForUnique(nums2) << endl;

    return 0;
}