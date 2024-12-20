#include<bits/stdc++.h>
using namespace std;
/*

You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

 

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
 

Constraints:

n == arr.length
1 <= n <= 10
0 <= arr[i] < n
All the elements of arr are unique.

*/

int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    int max_val = 0;
    for(int i=0;i<n;i++)
    {
        max_val = max(max_val,arr[i]);
        if(max_val==i)
        {
            ans++;
        }
    }
    return ans;
}
// Time Complexity : O(N)
// Space Complexity : O(1)

/*
int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    int prefixSum= 0;
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        prefixSum+=i;
        sum+=arr[i];
        if(prefixSum==sum)
        {
            cnt++;
        }
    }
    return ans;
}
// Time Complexity : O(N)
// Space Complexity : O(1)
*/

int main()
{
    vector<int> arr = {1,0,2,3,4};
    cout<<maxChunksToSorted(arr)<<endl;
    return 0;
}