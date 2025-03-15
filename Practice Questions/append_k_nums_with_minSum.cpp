#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums and an integer k. Append k unique positive integers that do not appear in nums to nums such that the resulting total sum is minimum.

Return the sum of the k integers appended to nums.

 

Example 1:

Input: nums = [1,4,25,10,25], k = 2
Output: 5
Explanation: The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.
Example 2:

Input: nums = [5,6], k = 6
Output: 25
Explanation: The six unique positive integers that do not appear in nums which we append are 1, 2, 3, 4, 7, and 8.
The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which is the minimum. 
The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so we return 25.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= 10^8
*/

typedef long long int ll;
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        ll sum = 0;
        sort(nums.begin(), nums.end());

        ll num = nums[0] - 1;
        if (num > 0) {
            if (k > num) {
                k -= num;
                sum += (num * (num + 1LL)) / 2;
            } else {
                sum += (k * (k + 1LL)) / 2;
                return sum;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                ll a = nums[i] + k;
                ll b = nums[i];

                sum += ((a * (a + 1LL)) / 2) - ((b * (b + 1LL)) / 2);
                break;
            } else {
                ll diff = nums[i + 1] - nums[i] - 1;
                if (diff > 0 && k > 0) {
                    if (k > diff) {
                        k -= diff;
                        ll a = nums[i] + diff;
                        ll b = nums[i];

                        sum += ((a * (a + 1LL)) / 2) - ((b * (b + 1LL)) / 2);
                    } else {
                        ll a = nums[i] + k;
                        ll b = nums[i];

                        sum += ((a * (a + 1LL)) / 2) - ((b * (b + 1LL)) / 2);
                        break;
                    }
                }
            }
        }
        return sum;
    }
};

/*
Time Complexity: O(NlogN)
Space Complexity: O(1)
*/

int main() {
    Solution s;
    vector<int> nums = {1,4,25,10,25};
    int k = 2;
    cout << s.minimalKSum(nums, k) << endl;
}