#include<bits/stdc++.h>
using namespace std; 

/*
You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.

Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7. Note that you should maximize the product before taking the modulo. 

 

Example 1:

Input: nums = [0,4], k = 5
Output: 20
Explanation: Increment the first number 5 times.
Now nums = [5, 4], with a product of 5 * 4 = 20.
It can be shown that 20 is maximum product possible, so we return 20.
Note that there may be other ways to increment nums to have the maximum product.
Example 2:

Input: nums = [6,3,3,2], k = 2
Output: 216
Explanation: Increment the second number 1 time and increment the fourth number 1 time.
Now nums = [6, 4, 3, 3], with a product of 6 * 4 * 3 * 3 = 216.
It can be shown that 216 is maximum product possible, so we return 216.
Note that there may be other ways to increment nums to have the maximum product.
 

Constraints:

1 <= nums.length, k <= 10^5
0 <= nums[i] <= 10^6

*/

class Solution {
public:
const int mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        for(int i =0;i<k;i++)
        {
            int num = pq.top();
            pq.pop();
            pq.push(num+1);
        }
        long long int prod =1;
        while(!pq.empty())
        {
            prod = (prod*pq.top())%mod;
            pq.pop();
        }
        return prod;
    }
};

/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

int main()
{
    Solution s;
    vector<int> nums = {6,3,3,2};
    int k = 2;
    cout<<s.maximumProduct(nums,k);
}