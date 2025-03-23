#include <bits/stdc++.h>
using namespace std;

/*

You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time.

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Input: start[] = [1, 2], end[] = [100, 99]
Output: 1
Constraints:
1 ≤ n ≤ 105
0 ≤ start[i] < end[i] ≤ 10^6

*/

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = start.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({end[i], start[i]});
        }

        int cnt = 1;
        auto it = pq.top();
        pq.pop();
        int first_start = it.second;
        int first_end = it.first;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            if (it.second > first_end)
            {
                cnt++;
                first_start = it.second;
                first_end = it.first;
            }
        }
        return cnt;
    }
};

/*
Time Complexity:O(NlongN+N);
Space Complexity:O(1)
*/

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    Solution obj;
    cout << obj.maxMeetings(start, end) << endl;
    return 0;
}