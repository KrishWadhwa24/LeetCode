#include<bits/stdc++.h>
using namespace std;

/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

Constraints:

n == graph.length
1 <= n <= 10^4
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 10^4].
*/


class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& graph, vector<int>& ans) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathvis, graph, ans)) 
                    return true;
            } else if (pathvis[it]) {
                return true;
            }
        }

        pathvis[node] = 0;
        ans.push_back(node);
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> ans;
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathvis, graph, ans);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time Complexity: O(V + E)
Space Complexity: O(V)+O(V)
*/

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> temp(m);
        for (int j = 0; j < m; j++)
        {
            cin >> temp[j];
        }
        graph[i] = temp;
    }
    Solution obj;
    vector<int> ans = obj.eventualSafeNodes(graph);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}