#include <bits/stdc++.h>
using namespace std;

/*
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.



Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation:
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation:
In this case, it is not possible to rotate the dominoes to make one row of values equal.


Constraints:

2 <= tops.length <= 2 * 10^4
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6
*/

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        char top = tops[0];
        char bottom = bottoms[0];
        int n = tops.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int common = 0;

        for (int i = 0; i < tops.size(); i++)
        {
            if (tops[i] == top && bottoms[i] == top)
                common++;
            else if (bottoms[i] == top)
                cnt2++;
            else if (tops[i] == top)
                cnt1++;
        }
        int mini = INT_MAX;
        if (cnt1 + cnt2 + common == n)
        {
            mini = min(mini, min(cnt1, cnt2));
        }
        cnt1 = 0;
        cnt2 = 0;
        common = 0;
        for (int i = 0; i < tops.size(); i++)
        {
            if (tops[i] == bottom && bottoms[i] == bottom)
            {
                common++;
            }
            else if (tops[i] == bottom)
                cnt1++;
            else if (bottoms[i] == bottom)
                cnt2++;
        }

        if (cnt1 + cnt2 + common == n)
        {
            mini = min(mini, min(cnt1, cnt2));
        }

        return mini == INT_MAX ? -1 : mini;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
where n is the number of dominoes.
*/

int main()
{
    Solution sol;
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};
    cout << sol.minDominoRotations(tops, bottoms) << endl; // Output: 2
    return 0;
}