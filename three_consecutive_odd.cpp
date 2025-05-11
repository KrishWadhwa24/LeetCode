#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.


Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.


Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
*/

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i <= n - 3; i++)
        {
            if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
            {
                return true;
            }
        }
        return false;
    }
};
/*
Time Complexity: O(n), where n is the size of the array.
Space Complexity: O(1), as we are using only a constant amount of space.
*/

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << s.threeConsecutiveOdds(arr) << endl; // Output: true
    return 0;
}