#include <bits/stdc++.h>
using namespace std;

/*
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.



Example 1:


Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
Example 2:


Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.


Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 10^5
k == queries.length
1 <= k <= 10^4
1 <= grid[i][j], queries[i] <= 10^6

*/

class Solution
{
public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int k = queries.size();
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < k; i++)
        {
            vec.push_back({queries[i], i});
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> ans(k, 0);
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        int cnt = 0;
        for (auto &it : vec)
        {
            while (!pq.empty() && pq.top().first < it.first)
            {
                auto x = pq.top();
                pq.pop();

                cnt++;
                for (int i = 0; i < 4; i++)
                {
                    int nrow = x.second.first + delrow[i];
                    int ncol = x.second.second + delcol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol])
                    {
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
            ans[it.second] = cnt;
        }
        return ans;
    }
};

/*
Time Complexity: O(KLogK+NmLogK)
Space Complexity: O(Nm+K)
Where K is the size of the queries array, N is the number of rows in the grid, and M is the number of columns in the grid.
*/

int main()
{
    Solution obj;
    vector<vector<int>> grid = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries = {5, 6, 2};
    vector<int> result = obj.maxPoints(grid, queries);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}