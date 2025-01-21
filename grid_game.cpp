#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

 

Example 1:


Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
Example 2:


Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.
Example 3:


Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
 

Constraints:

grid.length == 2
n == grid[r].length
1 <= n <= 5 * 10^4
1 <= grid[r][c] <= 10^5


Edge Case:

grid = [20 03 20 17 02 12 15 17 04 15
       20 10 13 14 15 05 02 03 14 03]

expected Answer : 63

*/

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long col = grid[0].size();
        long long bottom = 0;
        long long totalSum = 0;
        for (long long i = 0; i < col; i++) {
            totalSum += grid[0][i];
        }

        long long points = LLONG_MAX;

        for (long long i = 0; i < col; i++) {
            totalSum -= grid[0][i];
            points = min(max(totalSum, bottom), points);
            bottom += grid[1][i];
        }

        return points;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)

*/


// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int col = grid[0].size();
//         vector<long long> suffix(col, 0);
//         vector<long long> prefix(col, 0);

//         suffix[col - 1] = grid[0][col - 1];
//         for (int i = col - 2; i >= 0; --i) {
//             suffix[i] = suffix[i + 1] + grid[0][i];
//         }
//         prefix[0] = grid[1][0];
//         for (int i = 1; i < col; ++i) {
//             prefix[i] = prefix[i - 1] + grid[1][i];
//         }
//         long long points = LLONG_MAX;
//         for (int i = 0; i < col; ++i) {
//             long long top = (i + 1 < col) ? suffix[i + 1] : 0;
//             long long bottom = (i - 1 >= 0) ? prefix[i - 1] : 0;
//             points = min(points, max(top, bottom));
//         }

//         return points;
//     }
// };

/*
Time Complexity: O(n)+O9n)+O(n)
Space Complexity: O(n)
*/

int main()
{
    Solution s;
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};
    cout<<s.gridGame(grid)<<endl;
    return 0;
}