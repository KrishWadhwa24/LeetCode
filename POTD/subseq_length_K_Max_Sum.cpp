#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation:
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7.
Another possible subsequence is [4, 3].


Constraints:

1 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end(),
             [](auto &a, auto &b)
             { return a.first > b.first; });

        vector<pair<int, int>> topK(vec.begin(), vec.begin() + k);
        sort(topK.begin(), topK.end(),
             [](auto &a, auto &b)
             { return a.second < b.second; });
        vector<int> ans;
        for (auto &it : topK)
        {
            ans.push_back(it.first);
        }
        return ans;
    }
};

/*
Time Complexity: O(n log n + k log k + k)
Space Complexity: O(n)
Where n is the size of the input array nums.
*/
/*

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i =0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        vector<int> ans;
        vector<int> mark(n,0);
        while(pq.size()>n-k)
        {
            auto it = pq.top();
            pq.pop();

            mark[it.second] = 1;
        }

        for(int i =0;i<n;i++)
        {
            if(mark[i]==1)
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

Time Complexity: O(n log n + k+n)
Space Complexity: O(n)

*/

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 3, 3};
    int k = 2;
    vector<int> result = sol.maxSubsequence(nums, k);
    
    cout << "Result: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}