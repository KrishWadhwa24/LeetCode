#include <bits/stdc++.h>
using namespace std;

/*
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.



Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 7

Explanation:

The minimum time required is 7 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
Example 2:

Input: moveTime = [[0,0,0,0],[0,0,0,0]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
At time t == 3, move from room (1, 1) to room (1, 2) in one second.
At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 4



Constraints:

2 <= n == moveTime.length <= 750
2 <= m == moveTime[i].length <= 750
0 <= moveTime[i][j] <= 10^9

*/

class Solution
{
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, pair<int, int>>>,
                       vector<pair<int, pair<int, pair<int, int>>>>,
                       greater<pair<int, pair<int, pair<int, int>>>>>
            pq;

        pq.push({0, {0, {0, 0}}});
        vis[0][0] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int cnt = it.second.first;
            int r = it.second.second.first;
            int c = it.second.second.second;

            if (r == n - 1 && c == m - 1)
                return time;

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int waitTime = max(moveTime[nrow][ncol] - time, 0);
                    int newTime = waitTime + time + (cnt % 2 == 0 ? 1 : 2);

                    if (newTime < vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = newTime;
                        pq.push({newTime, {cnt + 1, {nrow, ncol}}});
                    }
                }
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n*m*log(n*m))
Space Complexity: O(n*m)
*/

int main()
{
    Solution s;
    vector<vector<int>> moveTime = {{0, 4}, {4, 4}};
    cout << s.minTimeToReach(moveTime) << endl; // Output: 7

    return 0;
}