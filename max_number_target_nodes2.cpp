#include <bits/stdc++.h>
using namespace std;

/*
There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.



Example 1:

Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]

Output: [8,7,7,8,8]

Explanation:

For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 4 from the second tree.
For i = 2, connect node 2 from the first tree to node 7 from the second tree.
For i = 3, connect node 3 from the first tree to node 0 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:

Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]

Output: [3,6,6,6,6]

Explanation:

For every i, connect node i of the first tree with any node of the second tree.




Constraints:

2 <= n, m <= 10^5
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.
*/

class Solution
{
private:
    vector<int> reach(vector<vector<int>> &adj, vector<int> &nodes)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int cnt = 0;
        int cnt2 = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int node = it.second;
            int steps = it.first;
            nodes[node] = steps % 2;
            if (steps % 2 == 0)
                cnt++;
            else
                cnt2++;

            for (auto &it : adj[node])
            {
                if (vis[it] == false)
                {
                    vis[it] = true;
                    q.push({1 + steps, it});
                }
            }
        }
        return {cnt, cnt2};
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                               vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for (auto &it : edges1)
        {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        for (auto &it : edges2)
        {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        vector<int> nodes(n, 0);
        vector<int> nodes2(m, 0);
        vector<int> even = reach(adj1, nodes);
        vector<int> odd = reach(adj2, nodes2);

        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++)
        {
            answer[i] = (nodes[i] == 0 ? even[0] : even[1]) + max(odd[0], odd[1]);
        }
        return answer;
    }
};

/*
Time Complexity: O(n + m), where n is the number of nodes in the first tree and m is the number of nodes in the second tree. We traverse each tree once to build the adjacency list and then again to calculate the reachability.
Space Complexity: O(n + m), where n is the number of nodes in the first tree and m is the number of nodes in the second tree. We use additional space for the adjacency lists and the visited arrays.
*/

int main()
{
    Solution sol;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
    vector<int> result = sol.maxTargetNodes(edges1, edges2);
    
    for (int i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}