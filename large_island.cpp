#include<bits/stdc++.h>
using namespace std;

/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};

private:
    int bfs(int r, int c, vector<vector<int>>& grid,
            vector<vector<int>>& mpp, int k, unordered_map<int, int>& mp) {
        mpp[r][c] = k;
        queue<pair<int, int>> q;
        q.push({r, c});
        int len = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            len++;
            int row = it.first;
            int col = it.second;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                    ncol < grid[0].size() && grid[nrow][ncol] == 1 &&
                    mpp[nrow][ncol] == -1) {
                    mpp[nrow][ncol] = k;
                    q.push({nrow, ncol});
                }
            }
        }

        mp[k] = len;
        return len;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxi = 0;
        int islandId = 2;
        vector<vector<int>> mpp(row, vector<int>(col, -1));
        unordered_map<int, int> mp;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && mpp[i][j] == -1) {
                    int len = bfs(i, j, grid, mpp, islandId, mp);
                    maxi = max(maxi, len);
                    islandId++;
                }
            }
        }
        if (maxi == row * col) return maxi;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    int len = 1;
                    unordered_set<int> uniqueIslands;
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];

                        if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col &&
                            grid[nrow][ncol] == 1) {
                            
                            int islandId = mpp[nrow][ncol];

                            if (uniqueIslands.find(islandId) == uniqueIslands.end()) {
                                len += mp[islandId]; 
                                uniqueIslands.insert(islandId);
                            }
                        }
                    }
                    maxi = max(maxi, len);
                }
            }
        }

        return maxi;
    }
};

/*
Time Complexity: O(N^2)
Space Complexity: O(N^2) + O(N)+ O(N)
*/

int main()
{
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    Solution obj;
    cout << obj.largestIsland(grid);
    return 0;
}