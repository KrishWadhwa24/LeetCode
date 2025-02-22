#include <bits/stdc++.h>
using namespace std;

/*
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 500
1 <= N <= 1000
0 <= ARR[i] <= 10^5

Where 'ARR[i]' denotes the 'i-th' element in the array/list.

Time Limit: 1 sec.
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
Explanation to Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24
Explanation to Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

*/

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    if (n == 0) return 0;
    int prev1 = nums[0];

    int curr = 0;
    for (int i = 1; i < n; i++)
    {
        int take = nums[i] + prev2;
        int notTake = 0 + prev1;

        curr = max(take, notTake);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

//Tabulation Method
/*
int maximumNonAdjacentSum(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0] = nums[0];
    for(int i =1;i<n;i++)
    {
        int take = nums[i] + (i-2>=0?dp[i-2]:0);
        int notTake = (i-1>=0?dp[i-1]:0);

        dp[i] = max(take,notTake);
    }
    return dp[n-1];
}


Time Complexity: O(N)
Space Complexity: O(N)
*/

//Memoization Method
/*
int maximumNonAdjacentSum(vector<int>& nums,int n,vector<int>& dp)
{
    if(n==0)
    {
        return nums[0];
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int take = nums[n] + maximumNonAdjacentSum(nums,n-2,dp);
    int notTake = maximumNonAdjacentSum(nums,n-1,dp);

    return dp[n] = max(take,notTake);
}

Time Complexity: O(N)
Space Complexity: O(N) + O(N)
*/

//Backtracking Method

/*
int maximumNonAdjacentSum(vector<int>& nums)
{
    int n = nums.size();
    return maximumNonAdjacentSum(nums,n,0);
}
int maximumNonAdjacentSum(vector<int> &nums, int n, int i)
{
    if (i >= n)
    {
        return 0;
    }

    int take = nums[i] + maximumNonAdjacentSum(nums, n, i + 2);
    int notTake = maximumNonAdjacentSum(nums, n, i + 1);

    return max(take, notTake);
}


Time Complexity: O(2^N)
Space Complexity: O(1)
*/


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << maximumNonAdjacentSum(nums) << endl;
    }
    return 0;
}