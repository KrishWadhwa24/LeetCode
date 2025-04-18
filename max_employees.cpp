#include<bits/stdc++.h>
using namespace std;

/*
A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

 

Example 1:


Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
Example 2:

Input: favorite = [1,2,0]
Output: 3
Explanation: 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
Example 3:


Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
 

Constraints:

n == favorite.length
2 <= n <= 10^5
0 <= favorite[i] <= n - 1
favorite[i] != i
*/

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> depth(n, 1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int next = favorite[node];
            depth[next] = max(depth[next], depth[node] + 1);
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }

        int longCyc = 0;
        int twoCyc = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                continue;

            int len = 0;
            int curr = i;
            while (indegree[curr] != 0) {
                indegree[curr] = 0;
                len++;
                curr = favorite[curr];
            }

            if (len == 2) {
                twoCyc += depth[i] + depth[favorite[i]] ;
            } else {
                longCyc = max(longCyc, len);
            }
        }
        return max(twoCyc, longCyc);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

int main() {
    Solution sol;
    vector<int> favorite = {2, 2, 1, 2};
    cout << sol.maximumInvitations(favorite) << endl;
    return 0;
}