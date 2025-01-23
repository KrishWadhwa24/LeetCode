#include<bits/stdc++.h>
using namespace std;

/*
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

 

Example 1:



Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
Example 2:



Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
Example 3:



Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1

*/

class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        int communicableServersCount = 0;
        vector<int> rowCounts(grid[0].size(), 0),
            lastServerInCol(grid.size(), -1);

        // First pass to count servers in each row and column
        for (int row = 0; row < grid.size(); ++row) {
            int serverCountInRow = 0;
            for (int col = 0; col < grid[row].size(); ++col)
                if (grid[row][col]) {
                    serverCountInRow++;
                    rowCounts[col]++;
                    lastServerInCol[row] = col;
                }
            // If there is more than one server in the row, increase the count
            if (serverCountInRow != 1)
                communicableServersCount += serverCountInRow,
                    lastServerInCol[row] = -1;
        }

        // Second pass to check if servers can communicate
        for (int row = 0; row < grid.size(); ++row)
            communicableServersCount += lastServerInCol[row] != -1 &&
                                        rowCounts[lastServerInCol[row]] > 1;

        return communicableServersCount;
    }
};

/*
Time complexity: O(m*n) + O(n)
Space complexity: O(m+n)
*/


// class Solution {
// public:
//     int countServers(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();

//         vector<int> Rows(row, 0);
//         vector<int> Cols(col, 0);
//         int cnt = 0;

//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     Rows[i]++;
//                     Cols[j]++;
//                     cnt++;
//                 }
//             }
//         }
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1 && Rows[i] == 1 && Cols[j] == 1) {
//                     cnt--;
//                 }
//             }
//         }

//         return cnt;
//     }
// };

/*
Time complexity: O(m*n)
Space complexity: O(m+n)
*/

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 0}, {1, 1}};
    cout << s.countServers(grid) << endl;
    return 0;
}