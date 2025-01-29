#include<bits/stdc++.h>
using namespace std;

/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/

class Solution {
    private:
    bool isCycle(vector<vector<int>>& adj, int src, int parent, vector<int>& vis) {
        vis[src] = 1;
        for (auto it : adj[src]) {
            if (!vis[it]) {
                if (isCycle(adj, it, src, vis)) 
                    return true;
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; i++) {
            auto it = edges[i];
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            vector<int> vis(n + 1, 0);
            if (isCycle(adj, it[0], -1, vis))
                return {it[0], it[1]};
        }
        return {};
    }
};

/*
Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

int main()
{
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> ans = s.findRedundantConnection(edges);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}