#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.



Example 1:

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
Example 2:

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.


Constraints:

3 <= arr.length <= 100
0 <= arr[i] <= 1000
0 <= a, b, c <= 1000
*/

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int n = arr.size();
        int ans = 0;
        vector<int> prefix(1000 + 1, 0);
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (abs(arr[j] - arr[k]) <= b)
                {
                    int r_j = arr[j] + a;
                    int l_j = arr[j] - a;

                    int r_k = arr[k] + c;
                    int l_k = arr[k] - c;

                    int l = max(l_j, l_k);
                    int r = min(r_k, r_j);

                    l = max(l, 0);
                    r = min(r, 1000);

                    if (l <= r)
                    {
                        if (l == 0)
                            ans += prefix[r];
                        else
                            ans += (prefix[r] - prefix[l - 1]);
                    }
                }
            }
            for (int i = arr[j]; i <= 1000; i++)
            {
                prefix[i]++;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2 + n * 1000) = O(n^2)
Space Complexity: O(1000) = O(1)
*/

int main()
{
    Solution s;
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int a = 7, b = 2, c = 3;
    cout << s.countGoodTriplets(arr, a, b, c) << endl; // Output: 4
    return 0;
}