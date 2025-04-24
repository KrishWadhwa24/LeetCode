#include <bits/stdc++.h>
using namespace std;

/*
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.



Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2000

*/

class Solution
{
private:
    int func(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        int l = 0;
        int r = 0;
        int cnt = 0;
        while (r < nums.size())
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);

                l++;
            }

            if (mpp.size() <= k)
            {
                cnt += (r - l + 1);
            }
            r++;
        }
        return cnt;
    }

public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto &it : nums)
        {
            st.insert(it);
        }

        int k = st.size();
        return func(nums, k) - func(nums, k - 1);
    }
};

/*
Time Complexity: O(N * log(N))
Space Complexity: O(N)
*/

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 1, 2, 2};
    cout << s.countCompleteSubarrays(nums) << endl;

    nums = {5, 5, 5, 5};
    cout << s.countCompleteSubarrays(nums) << endl;

    return 0;
}