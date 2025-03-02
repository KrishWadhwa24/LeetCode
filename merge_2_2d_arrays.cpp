#include <bits/stdc++.h>
using namespace std;

/*
You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
Return the resulting array. The returned array must be sorted in ascending order by id.



Example 1:

Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
Output: [[1,6],[2,3],[3,2],[4,6]]
Explanation: The resulting array contains the following:
- id = 1, the value of this id is 2 + 4 = 6.
- id = 2, the value of this id is 3.
- id = 3, the value of this id is 2.
- id = 4, the value of this id is 5 + 1 = 6.
Example 2:

Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
Explanation: There are no common ids, so we just include each id with its value in the resulting list.


Constraints:

1 <= nums1.length, nums2.length <= 200
nums1[i].length == nums2[j].length == 2
1 <= idi, vali <= 1000
Both arrays contain unique ids.
Both arrays are in strictly ascending order by id.
*/

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                    vector<vector<int>> &nums2)
    {
        int pointer1 = 0;
        int pointer2 = 0;
        vector<vector<int>> ans;
        while (pointer1 < nums1.size() && pointer2 < nums2.size())
        {
            if (nums1[pointer1][0] > nums2[pointer2][0])
            {
                ans.push_back({nums2[pointer2][0], nums2[pointer2][1]});
                pointer2++;
            }
            else if (nums1[pointer1][0] < nums2[pointer2][0])
            {
                ans.push_back({nums1[pointer1][0], nums1[pointer1][1]});
                pointer1++;
            }
            else
            {
                ans.push_back({nums1[pointer1][0],
                               nums1[pointer1][1] + nums2[pointer2][1]});
                pointer1++;
                pointer2++;
            }
        }

        while (pointer1 < nums1.size())
        {
            ans.push_back({nums1[pointer1][0], nums1[pointer1][1]});
            pointer1++;
        }

        while (pointer2 < nums2.size())
        {
            ans.push_back({nums2[pointer2][0], nums2[pointer2][1]});
            pointer2++;
        }
        return ans;
    }
};

/*
Time Complexity: O(n + m), where n is the size of nums1 and m is the size of nums2.
Space Complexity: O(1).
*/

/*

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
vector<vector<int>>& nums2) { map<int,int> mpp; for(auto &it:nums1)
        {
            mpp[it[0]] = it[1];
        }

        for(auto &it:nums2)
        {
            if(mpp.find(it[0])!=mpp.end())
            {
                mpp[it[0]]+=it[1];
            }else
            {
                mpp[it[0]] = it[1];
            }
        }

        vector<vector<int>> ans;
        for(auto &it:mpp)
        {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

Time Complexity: O(n + m), where n is the size of nums1 and m is the size of nums2.
Space Complexity: O(n + m).
*/

int main()
{
    Solution s;
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> ans = s.mergeArrays(nums1, nums2);
    for (auto &it : ans)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
    return 0;
}
