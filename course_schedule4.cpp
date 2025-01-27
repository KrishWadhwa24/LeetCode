#include<bits/stdc++.h>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

 

Example 1:


Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.
Example 2:

Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.
Example 3:


Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
 

Constraints:

2 <= numCourses <= 100
0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
prerequisites[i].length == 2
0 <= ai, bi <= numCourses - 1
ai != bi
All the pairs [ai, bi] are unique.
The prerequisites graph has no cycles.
1 <= queries.length <= 104
0 <= ui, vi <= numCourses - 1
ui != vi
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<bool> ans;
        map<int, unordered_set<int>> mpp;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                mpp[it].insert(node);
                for (auto pre : mpp[node])
                    mpp[it].insert(pre);

                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        for (auto it : queries) {
            if (mpp[it[1]].find(it[0]) != mpp[it[1]].end()) {
                ans.push_back(true);
            } else
                ans.push_back(false);
        }
        return ans;
    }
};
/*
Time Complexity: O(N^3+Q)
Space Complexity: O(N^2)
*/

/*
class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>>& adj, vector<int>& vis) {
        if (src == dest) return true;
        vis[src] = 1;

        for (auto it : adj[src]) {
            if (!vis[it]) {
                if (dfs(it, dest, adj, vis))
                    return true;
            }
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>&
prerequisites, vector<vector<int>>& queries) { vector<vector<int>>
adj(numCourses); for (auto it : prerequisites) { adj[it[0]].push_back(it[1]);
        }

        vector<bool> ans;
        for (auto it : queries) {
            vector<int> vis(numCourses, 0);
            ans.push_back(dfs(it[0], it[1], adj, vis));
        }

        return ans;
    }
};

Time Complexity: O(N^2+Q)
Space Complexity: O(N^2)
*/

int main()
{
    Solution s;
    vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}};
    vector<vector<int>> queries = {{1, 0}, {1, 2}};
    vector<bool> ans = s.checkIfPrerequisite(3, prerequisites, queries);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}