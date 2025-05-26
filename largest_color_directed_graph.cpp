#include <bits/stdc++.h>
using namespace std;

/*
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.



Example 1:



Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
Example 2:



Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.


Constraints:

n == colors.length
m == edges.length
1 <= n <= 10^5
0 <= m <= 10^5
colors consists of lowercase English letters.
0 <= aj, bj < n

*/

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        vector<vector<int>> best(n, vector<int>(26, 0));
        int visited = 0, maxi = 1;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                best[i][colors[i] - 'a'] = 1;
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visited++;

            for (int next : adj[node])
            {

                for (int c = 0; c < 26; c++)
                {
                    best[next][c] = max(best[next][c], best[node][c] + (colors[next] - 'a' == c ? 1 : 0));
                    maxi = max(maxi, best[next][c]);
                }

                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return visited == n ? maxi : -1;
    }
};

/*
Time Complexity: O(n + m), where n is the number of nodes and m is the number of edges. Each node and edge is processed once.
Space Complexity: O(n + m), for the adjacency list and the indegree array. The best array also takes O(n * 26) space, but since 26 is a constant, it can be considered as O(n).
*/

int main()
{
    Solution sol;
    string colors = "abaca";
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    int result = sol.largestPathValue(colors, edges);
    cout << result << endl; // Output: 3
    return 0;
}