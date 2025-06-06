#include <bits/stdc++.h>
using namespace std;

/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.



Example 1:


Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
Example 2:


Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.


Constraints:

n == edges.length
2 <= n <= 10^5
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n
*/

class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dist(n, -1), dist2(n, -1);

        int curr = node1;
        int d = 0;
        while (curr != -1 && dist[curr] == -1)
        {
            dist[curr] = d++;
            curr = edges[curr];
        }

        d = 0;
        curr = node2;
        while (curr != -1 && dist2[curr] == -1)
        {
            dist2[curr] = d++;
            curr = edges[curr];
        }

        int mini = INT_MAX;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] != -1 && dist2[i] != -1 && mini > max(dist[i], dist2[i]))
            {
                mini = max(dist[i], dist2[i]);
                index = i;
            }
        }
        return index;
    }
};

/*
Time Complexity: O(N)
Space Complexity :O(n);
*/

/*

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist(n,-1);
        queue<pair<int,int>> q;
        q.push({0,node1});

        dist[node1] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int node = it.second;
            int step = it.first;

            int next = edges[node];
            if(next!=-1 && dist[next]==-1)
            {
                dist[next] = step+1;
                q.push({1+step,next});
            }
        }
        vector<int> dist2(n,-1);
        q.push({0,node2});
        dist2[node2] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int node = it.second;
            int step = it.first;

            int next = edges[node];
            if(next!=-1 && dist2[next]==-1)
            {
                dist2[next] = 1+step;
                q.push({1+step,next});
            }
        }
        int mini = INT_MAX;
        int index = -1;
        for(int i =0;i<n;i++)
        {
            if(dist[i]!=-1 && dist2[i]!=-1 && mini>max(dist[i],dist2[i]))
            {
                mini = max(dist[i],dist2[i]);
                index = i;
            }
        }
        return index;

    }
};

Time Complexity: O(N)
Space Complexity :O(n);
*/

int main()
{
    Solution sol;
    vector<int> edges = {2, 2, 3, -1};
    int node1 = 0, node2 = 1;
    int result = sol.closestMeetingNode(edges, node1, node2);
    cout << "The closest meeting node is: " << result << endl; // Output: 2
    return 0;
}