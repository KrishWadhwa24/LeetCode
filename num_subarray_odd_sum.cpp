#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 100
*/

class Solution {
    long long int MOD = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int prefix = arr[0];
        int cnt = 0;
        int even = 0;
        int odd = 0;
        if (prefix % 2 != 0) {
            cnt++;
            odd++;
        } else {
            even++;
        }

        for (int i = 1; i < n; i++) {

            prefix += arr[i];
            if (prefix % 2 != 0) {
                cnt = (cnt + 1) % MOD;
                odd++;
            } else {
                even++;
            }

            if (prefix % 2) {
                cnt = (cnt + even) % MOD;
            } else {
                cnt = (cnt + odd) % MOD;
            }
        }
        return cnt % MOD;
    }
};

/*
Time Complexity: O(N), where N is the length of the array arr.
Space Complexity: O(1).
*/

/*
Better Solution
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> dpEven(n), dpOdd(n);

        if (arr[n - 1]%2 == 0) {
            dpEven[n - 1] = 1;
        } else {
            // The last element is odd
            dpOdd[n - 1] = 1;
        }

        for (int num = n - 2; num >= 0; num--) {
            if (arr[num]%2 == 1) {
                // Odd element contributes to odd subarrays
                dpOdd[num] = (1 + dpEven[num + 1]) % MOD;
                // Even element continues the pattern
                dpEven[num] = dpOdd[num + 1];
            } else {
                // Even element contributes to even subarrays
                dpEven[num] = (1 + dpEven[num + 1]) % MOD;
                // Odd element continues the pattern
                dpOdd[num] = dpOdd[num + 1];
            }
        }

        int count = 0;
        for (auto oddCount : dpOdd) {
            count += oddCount;
            count %= MOD;
        }

        return count;
    }
};

Time Complexity: O(N), where N is the length of the array arr.  
Space Complexity: O(N).
*/

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5};
    cout << sol.numOfSubarrays(arr) << endl;
    arr = {2, 4, 6};
    cout << sol.numOfSubarrays(arr) << endl;
    arr = {1, 2, 3, 4, 5, 6, 7};
    cout << sol.numOfSubarrays(arr) << endl;
    return 0;
}