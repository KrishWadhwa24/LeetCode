/*
"An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

 

Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> problem(n, 0);
        for (int i = 1; i < n; i++) {
            if ((nums[i] % 2 == 0 && nums[i - 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i - 1] % 2 != 0)) {
                problem[i] = 1;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            problem[i] += problem[i - 1];
        }

        vector<bool> ans;
        for (auto& it : queries) {
            int start = it[0];
            int end = it[1];
            if (start < 0 || end >= n || start > end) {
                ans.push_back(false);
                continue;
            }
            
            int diff = problem[end] - problem[start];
            ans.push_back(diff == 0);
        }

        return ans;
    }
};



//Brute Forcce

// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<bool> ans;
        
//         for (auto query : queries) {
//             int start = query[0];
//             int end = query[1];
            
//             if (start < 0 || end >= nums.size() || start > end) {
//                 ans.push_back(false);
//                 continue;
//             }
//             bool isSpecial = true;
//             for (int j = start + 1; j <= end; ++j) {
//                 if ((nums[j] % 2 == 0 && nums[j - 1] % 2 == 0) || 
//                     (nums[j] % 2 != 0 && nums[j - 1] % 2 != 0)) {
//                     isSpecial = false;
//                     break;
//                 }
//             }
//             ans.push_back(isSpecial);
//         }
//         return ans;
//     }
// };

int main() {
    Solution s;
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,4}};
    vector<bool> ans = s.isArraySpecial(nums, queries);
    for (auto a : ans) {
        if(a) cout << "true" << " ";
        else cout << "false" << " ";
    }
    cout << endl;
    return 0;
}