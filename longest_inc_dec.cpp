#include<bits/stdc++.h>
using namespace std;

/*
You are given an array of integers nums. Return the length of the longest 
subarray
 of nums which is either 
strictly increasing
 or 
strictly decreasing
.

 

Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50

*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi =1;
        int cnt1 = 1;
        int cnt2 =1;
        for(int i =0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                cnt2 =1;
                cnt1++;
                maxi = max(cnt1,maxi);
            }else
            if(nums[i]>nums[i+1])
            {
                cnt1 =1;
                cnt2++;
                maxi = max(cnt2,maxi);
            }else
            {
                cnt1 =1;
                cnt2 =1;
            }
        }
        return maxi;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

int main()
{
    vector<int> nums = {1,4,3,3,2};
    Solution obj;
    cout<<obj.longestMonotonicSubarray(nums);
    return 0;
}