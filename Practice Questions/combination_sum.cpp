#include<bits/stdc++.h>
using namespace std;

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

*/

class Solution {
public:
    void printS(int ind,int target, vector<int>& arr, vector<int>& ds,int n,vector<vector<int>>& ans) {
        if(ind==n)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }

        if(arr[ind]<=target)
        {
            ds.push_back(arr[ind]);
            printS(ind,target-arr[ind],arr,ds,n,ans);
            ds.pop_back();
        }
        printS(ind+1,target,arr,ds,n,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        printS(0,target, candidates, ds,n,ans);
        return ans;
    }
};

/*
Time Complexity: O(2^N)
Space Complexity: O(K*X)
*/

int main()
{
    Solution s;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = s.combinationSum(candidates,target);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}