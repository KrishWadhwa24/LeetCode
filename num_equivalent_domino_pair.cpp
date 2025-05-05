#include <bits/stdc++.h>
using namespace std;

/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].



Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
Example 2:

Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3


Constraints:

1 <= dominoes.length <= 4 * 10^4
dominoes[i].length == 2
1 <= dominoes[i][j] <= 9

*/

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> mpp;
        for (auto &it : dominoes)
        {
            auto x = it[0];
            auto y = it[1];

            if (x >= y)
                mpp[{y, x}]++;
            else
                mpp[{x, y}]++;
        }
        int cnt = 0;
        for (auto &it : mpp)
        {
            if (it.second >= 2)
            {
                cnt += (it.second * (it.second - 1)) / 2;
            }
        }
        return cnt;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is the number of dominoes.
*/

int main()
{
    Solution sol;
    vector<vector<int>> dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    cout << sol.numEquivDominoPairs(dominoes) << endl; // Output: 1
    return 0;
}