#include <bits/stdc++.h>
using namespace std;

/*

You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. 
Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated 
with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: id = [1, 2, 3, 4, 5], deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
Constraints:
1 <=  id.size() == deadline.size() == profit.size() <= 10^5
1 <= id[i], deadline[i] <= id.size()
1 <= profit <= 500

*/

class Solution
{
public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit)
    {
        priority_queue<pair<int, int>> pq;
        int n = deadline.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi,deadline[i]);
            pq.push({profit[i], deadline[i]});
        }
        vector<int> time(maxi + 1, -1);
        int cnt = 0;
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int t = it.second;
            while (t > 0 && time[t] != -1)
            {
                t--;
            }
            if (t > 0)
            {
                time[t] = 1;
                sum += it.first;
                cnt++;
            }
        }
        return {cnt, sum};
    }
};

/*
Time Complexity: O(NlogN + N*maxi)
Space Complexity: O(N)
*/

int main()
{
    vector<int> id = {1, 2, 3, 4};
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 1, 40, 30};
    Solution obj;
    vector<int> ans = obj.JobSequencing(id, deadline, profit);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}