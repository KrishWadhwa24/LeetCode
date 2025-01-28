#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

Example 1:


Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10
*/

class Solution {
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int maxi = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    bfs(maxi, grid, row, col, vis, i, j);
                }
            }
        }
        return maxi;
    }

private:
    void bfs(int& maxi, vector<vector<int>>& grid, int r, int c,
             vector<vector<int>>& vis, int startRow, int startCol) {

        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        vis[startRow][startCol] = 1;
        int sum = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            sum += grid[it.first][it.second];
            for (int i = 0; i < 4; i++)
            {
                int nrow = it.first + delrow[i];
                int ncol = it.second + delcol[i];
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol] && grid[nrow][ncol] > 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        maxi = max(maxi, sum);
    }
    /*
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int& sum) {
        vis[i][j] = 1;
        sum += grid[i][j];

        for (int dir = 0; dir < 4; dir++) {
            int nrow = i + delrow[dir];
            int ncol = j + delcol[dir];
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() &&
                !vis[nrow][ncol] && grid[nrow][ncol] > 0) {
                dfs(nrow, ncol, vis, grid, sum);
            }
        }
    }

    Time complexity: O(N*M)
    Space complexity: O(N*M)
    */
};

/*
Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 2, 1, 0},
                                 {4, 0, 0, 3},
                                 {1, 0, 0, 4},
                                 {0, 3, 2, 0}};
    cout << s.findMaxFish(grid) << endl;
    return 0;
}