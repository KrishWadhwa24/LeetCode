#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d.

Examples :

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Input: arr[] = [1, 1, 1, 1], d = 0
Output: 6
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr.
Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2
Constraint:
1 <= arr.size() <= 50
0 <= d  <= 50
0 <= arr[i] <= 6
*/

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {

        int n = arr.size();
        int sum = 0;
        for (auto &it : arr)
        {
            sum += it;
        }

        if (sum < d || (sum - d) % 2 != 0)
            return 0;

        int target = (sum - d) / 2;

        vector<int> front(target + 1, 0);
        front[0] = 1;
        if (arr[0] <= target)
        {
            front[arr[0]] += 1;
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(target + 1, 0);
            curr[0] = 1;
            for (int sum2 = 0; sum2 <= target; sum2++)
            {
                int notTake = front[sum2];
                int pick = 0;

                if (arr[i] <= sum2)
                {
                    pick += front[sum2 - arr[i]];
                }

                curr[sum2] = pick + notTake;
            }
            front = curr;
        }

        return front[target];
    }
};
/*
Time Complexity: O(N*target), where N is the size of the array arr.
Space Complexity: O(target) + O(target) = O(target), where N is the size of the array arr.
*/

/*

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for (int num : arr) sum+= num;
        if(sum<d || (sum-d)%2!=0)
        return 0;

        int target = (sum - d)/2;

        vector<vector<int>> dp(n,vector<int>(target+1,0));

        for(int i =0;i<n;i++)
        {
            dp[i][0] =1;
        }

        if(arr[0]<=target)
        {
            dp[0][arr[0]]+=1;
        }

        for(int i =1;i<n;i++)
        {
            for(int sum2 = 0;sum2<=target;sum2++)
            {
                int notTake = dp[i-1][sum2];

                int take = 0;
                if(arr[i]<=sum2)
                {
                    take+=dp[i-1][sum2-arr[i]];
                }

                dp[i][sum2] = take+notTake;
            }
        }

        return dp[n-1][target];
    }
};

Time Complexity: O(N*target), where N is the size of the array arr.
Space Complexity: O(N*target) + O(N) = O(N*target), where N is the size of the array arr.
*/

/*

typedef long long int ll;
class Solution {
private:
    int func(vector<int>& arr, int ind, int k, vector<vector<int>>& dp) {
        // Corrected base case
        if (ind == 0) {
            if (k == 0 && arr[0] == 0) return 2; // If first element is 0 and target is 0, we can pick or not pick
            if (k == 0 || arr[0] == k) return 1; // If target is 0 or first element equals target
            return 0; // Otherwise no valid way
        }

        if (dp[ind][k] != -1) return dp[ind][k];

        int notpick = func(arr, ind - 1, k, dp);
        int pick = 0;
        if (arr[ind] <= k) {
            pick = func(arr, ind - 1, k - arr[ind], dp);
        }

        return dp[ind][k] = pick + notpick;
    }

public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        ll total_sum = 0;
        for (int num : arr) total_sum += num;

        // Check if valid partition is possible
        // s1 + s2 = total_sum
        // s1 - s2 = d
        // 2*s2 = total_sum - d
        if ((total_sum - d) < 0 || (total_sum - d) % 2 != 0) return 0;

        int target = (total_sum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return func(arr, n - 1, target, dp);
    }
};

Time Complexity: O(N*target), where N is the size of the array arr.
Space Complexity: O(N*target) + O(N) = O(N*target), where N is the size of the array arr.
*/

int main()
{
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    Solution sol;
    cout << sol.countPartitions(arr, d) << endl; // Output: 1
    return 0;
}