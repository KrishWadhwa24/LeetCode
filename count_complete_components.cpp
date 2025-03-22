#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.



Example 1:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
Example 2:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.


Constraints:

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.

*/

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, int &cnt, vector<int> &component, vector<int> &vis)
    {
        component.push_back(node);
        vis[node] = 1;
        cnt++;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, cnt, component, vis);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            degree[u]++;
            degree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int cnt = 0;
                vector<int> component;
                dfs(i, adj, cnt, component, vis);

                bool isComplete = true;
                for (auto &it : component)
                {
                    if (degree[it] != cnt - 1)
                    {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete)
                    ans++;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(N+M), where N is the number of vertices in the graph.
Space Complexity: O(N+M)
*/

int main()
{
    Solution s;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    cout << s.countCompleteComponents(n, edges) << endl;
    return 0;
}