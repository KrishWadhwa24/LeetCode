#include <bits/stdc++.h>
using namespace std;

/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.



Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1


Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 are not the starting points of any snake or ladder.

*/

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> board2(n * n + 1);
        int k = 1;
        int left = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (left)
            {
                for (int j = 0; j < n; j++)
                {
                    board2[k++] = board[i][j];
                }
            }
            else
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    board2[k++] = board[i][j];
                }
            }
            left = !left;
        }

        queue<pair<int, int>> q;
        q.push({0, 1});
        int mini = n * n;
        vector<bool> vis(n * n + 1, false);
        vis[1] = true;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int move = it.first;
            int node = it.second;

            if (node == n * n)
            {
                return move;
            }
            for (int i = node + 1; i <= min(node + 6, n * n); i++)
            {
                int next = board2[i] == -1 ? i : board2[i];
                if (!vis[next])
                {
                    vis[next] = true;
                    q.push({1 + move, next});
                }
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2), where n is the size of the board. We traverse each cell at most once.
Space Complexity: O(n^2), for the queue and visited array.
*/

int main()
{
    Solution s;
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};
    int ans = s.snakesAndLadders(board);
    cout << ans << "\n";
    return 0;
}