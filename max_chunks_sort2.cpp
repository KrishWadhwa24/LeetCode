//Hard Level Question
#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer array arr.

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

 

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
 

Constraints:

1 <= arr.length <= 2000
0 <= arr[i] <= 10^8

*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(),nums.end());
        long long int prefixSum = 0;
        long long int sum = 0;
        int cnt = 0;
        for(int i = 0;i<nums.size();i++)
        {
            prefixSum += arr[i];
            sum += nums[i];

            if(prefixSum == sum)
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> arr = {2,1,3,4,4};
    Solution s;
    cout<<s.maxChunksToSorted(arr);
    return 0;
}