#include<bits/stdc++.h>
using namespace std;

/*
You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.

 

Example 1:

Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
 

Constraints:

1 <= nums1.length, nums2.length <= 10^5
0 <= nums1[i], nums2[j] <= 10^9
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if(len1%2==0 && len2%2==0)
        {
            return 0;
        }else
        if(len1%2!=0 && len2%2==0)
        {
            int XOR = 0;
            for(int i =0;i<len2;i++)
            {
                XOR = XOR^nums2[i];
            }
            return XOR;
        }else
        if(len1%2==0 && len2%2!=0)
        {
            int XOR=0;
            for(int i =0;i<len1;i++)
            {
                XOR= XOR^nums1[i];
            }
            return XOR;
        }else
        {
            int XOR1 =0;
            int XOR2 =0;
            for(int i =0;i<len1;i++)
            {
                XOR1= XOR1^nums1[i];
            }
            for(int i =0;i<len2;i++)
            {
                XOR2 = XOR2^nums2[i];
            }

            return XOR1^XOR2;
        }
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main() {
    Solution s;
    vector<int> nums1 = {2,1,3};
    vector<int> nums2 = {10,2,5,0};
    cout<<s.xorAllNums(nums1,nums2)<<endl;
    return 0;
}