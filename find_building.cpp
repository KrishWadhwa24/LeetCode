#include<bits/stdc++.h>
using namespace std;
/*
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot 
move to a common building on query i, set ans[i] to -1.

 

Example 1:

Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
Output: [2,5,-1,5,2]
Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2]. 
In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5]. 
In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
In the fifth query, Alice and Bob are already in the same building.  
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
Example 2:

Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
Output: [7,6,-1,4,6]
Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

 

Constraints:

1 <= heights.length <= 5 * 104
1 <= heights[i] <= 109
1 <= queries.length <= 5 * 104
queries[i] = [ai, bi]
0 <= ai, bi <= heights.length - 1
*/
// class Solution {
// public:
//     vector<int> leftmostBuildingQueries(vector<int>& heights,
//                                         vector<vector<int>>& queries) {
//         vector<vector<vector<int>>> storeQueries(heights.size());
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
//             maxIndex;
//         vector<int> result(queries.size(), -1);

//         // Store the mappings for all queries in storeQueries.
//         for (int currQuery = 0; currQuery < queries.size(); currQuery++) {
//             int a = queries[currQuery][0], b = queries[currQuery][1];
//             if (a < b && heights[a] < heights[b]) {
//                 result[currQuery] = b;
//             } else if (a > b && heights[a] > heights[b]) {
//                 result[currQuery] = a;
//             } else if (a == b) {
//                 result[currQuery] = a;
//             } else {
//                 storeQueries[max(a, b)].push_back(
//                     {max(heights[a], heights[b]), currQuery});
//             }
//         }

//         for (int index = 0; index < heights.size(); index++) {
//             // If the priority queue's minimum pair value is less than the
//             // current index of height, it is an answer to the query.
//             while (!maxIndex.empty() && maxIndex.top()[0] < heights[index]) {
//                 result[maxIndex.top()[1]] = index;
//                 maxIndex.pop();
//             }
//             // Push the with their maximum index as the current index in the
//             // priority queue.
//             for (auto& element : storeQueries[index]) {
//                 maxIndex.push(element);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        stack<int> st;
        vector<int> vec(heights.size());
        for (int i = heights.size() - 1; i >= 0; i--) {
            
            while (!st.empty() && heights[i] >= heights[st.top()]) {
                st.pop();
            }
            vec[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        vector<int> ans;
        for(auto it:queries)
        {
            int start = it[0];
            int end = it[1];
            if(start>end)
            swap(start,end);
            int b1 = vec[start];
            int b2 = vec[end];
            if(start==end||heights[start]<heights[end])
            ans.push_back(end);
            else
            if(vec[start]==-1 || vec[end]==-1)
            ans.push_back(-1);
            else
            {
                int maxi = max(vec[start],vec[end]);
                if(heights[maxi]>heights[start] && heights[maxi]>heights[end])
                ans.push_back(maxi);
                else{
                while(maxi!=-1 && (heights[maxi]<heights[start] || heights[maxi]<heights[end]))
                {
                    maxi = vec[maxi];
                }
                if(maxi!=-1 && heights[maxi]>heights[start] && heights[maxi]>heights[end])
                ans.push_back(maxi);
                else
                ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {6,4,8,5,2,7};
    vector<vector<int>> queries = {{0,1},{0,3},{2,4},{3,4},{2,2}};
    vector<int> ans = s.leftmostBuildingQueries(heights,queries);
    for(auto it:ans)
    cout<<it<<" ";
    cout<<endl;
    return 0;
}