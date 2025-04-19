#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2
 

Constraints:

2 <= values.length <= 5 * 10^4
1 <= values[i] <= 1000
*/

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int val = 0;
        int maxi = 0;
        for (int i = 0; i < values.size() - 1; i++)
        {
            val = max(val, values[i] + i);
            maxi = max(maxi, val + values[i + 1] - (i + 1));
        }
        return maxi;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main()
{
    Solution obj;
    vector<int> values = {8, 1, 5, 2, 6};
    cout << obj.maxScoreSightseeingPair(values) << endl; // Output: 11
    return 0;
}