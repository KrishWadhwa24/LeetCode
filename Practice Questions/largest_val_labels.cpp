#include <bits/stdc++.h>
using namespace std;

/*
You are given n item's value and label as two integer arrays values and labels. You are also given two integers numWanted and useLimit.

Your task is to find a subset of items with the maximum sum of their values such that:

The number of items is at most numWanted.
The number of items with the same label is at most useLimit.
Return the maximum sum.



Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1

Output: 9

Explanation:

The subset chosen is the first, third, and fifth items with the sum of values 5 + 3 + 1.

Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2

Output: 12

Explanation:

The subset chosen is the first, second, and third items with the sum of values 5 + 4 + 3.

Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1

Output: 16

Explanation:

The subset chosen is the first and fourth items with the sum of values 9 + 7.



Constraints:

n == values.length == labels.length
1 <= n <= 2 * 10^4
0 <= values[i], labels[i] <= 2 * 10^4
1 <= numWanted, useLimit <= n

*/

class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        vector<pair<int, int>> arr;
        for (int i = 0; i < values.size(); i++)
        {
            arr.push_back({values[i], labels[i]});
        }

        sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });

        int maxi = 0, cnt = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i].second]++;
            if (mpp[arr[i].second] <= useLimit && cnt < numWanted)
            {
                cnt++;
                maxi += arr[i].first;
            }
            else if (cnt >= numWanted)
                break;
        }
        return maxi;
    }
};


// Time Complexity: O(nlogn) + O(n)
// Space Complexity: O(n) +O(n)

int main()
{
    Solution s;
    vector<int> values = {5, 4, 3, 2, 1};
    vector<int> labels = {1, 1, 2, 2, 3};
    int numWanted = 3;
    int useLimit = 1;
    cout << s.largestValsFromLabels(values, labels, numWanted, useLimit) << endl;
    return 0;
}