#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

class Solution {
    private:
    long digitSum(int n)
    {
        long answer =0;
        while(n!=0)
        {
            answer += n%10;
            n/=10;
        }
        return answer;
    }
public:
    int maximumSum(vector<int>& nums) {
        vector<int> mpp(82,0);
        long answer = -1;
        long sum;

        for(int i =0;i<nums.size();i++)
        {
            sum = digitSum(nums[i]);
            if(mpp[sum] && (answer<(mpp[sum]+nums[i])))
            {
                answer = mpp[sum]+nums[i];
            }
            mpp[sum] = max(mpp[sum],nums[i]);
        }
        return answer;
    }
};

/*
Time Complexity : O(N), where N is the length of the array nums.
Space Complexity : O(1).
*/

/*
class Solution {
    private:
    int findSum(int n)
    {
        int sum = 0;
        while(n!=0)
        {
            int rem = n%10;
            sum+=rem;
            n/=10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> mpp;
        for(auto it:nums)
        {
            mpp[findSum(it)].push(it);
        }
        int maxi = INT_MIN;
        for(auto it:mpp)
        {
            if(it.second.size()<2)
            continue;

            int sum = it.second.top();
            it.second.pop();
            sum+=it.second.top();
            maxi = max(maxi,sum);
        }
        return maxi==INT_MIN?-1:maxi;
    }
};

Time Complexity : O(N), where N is the length of the array nums.
Space Complexity : O(N)

*/

int main()
{
    Solution s;
    vector<int> nums = {18,43,36,13,7};
    cout<<s.maximumSum(nums)<<endl;
    return 0;
}