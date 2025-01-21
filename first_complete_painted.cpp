#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

 

Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
 

Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 10^5
1 <= m * n <= 10^5
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.

*/

// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         int row = mat.size();
//         int col = mat[0].size();
//         unordered_map<int,pair<int,int>> mpp;
//         for(int i =0;i<row;i++)
//         {
//             for(int j =0;j<col;j++)
//             {
//                 mpp[mat[i][j]]= {i,j};
//             }
//         }

//         vector<int> Rows(row,0);
//         vector<int> Cols(col,0);
//         for(int i=0;i<arr.size();i++)
//         {
//             auto it = mpp[arr[i]];
//             int r = it.first;
//             int c= it.second;

//             Rows[r]++;
//             Cols[c]++;
//             if(Rows[r]==col|| Cols[c]==row)
//             return i;
//         }
//         return -1;
//     }
// };
/*
time complexity: O(m*n) + O(arr.size()) = O(m*n)
space complexity: O(m*n)+O(m)+O(n) = O(m*n)
*/

//Space optimised code
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]=i;
        }

        int result = INT_MAX;
        int row = mat.size();
        int col = mat[0].size();

        for(int i =0;i<row;i++)
        {
            int lastElement = INT_MIN;
            for(int j =0;j<col;j++)
            {
                int index = mpp[mat[i][j]];
                lastElement = max(lastElement,index);
            }
            result = min(result,lastElement);
        }

        for(int i=0;i<col;i++)
        {
            int lastElement = INT_MIN;
            for(int j = 0;j<row;j++)
            {
                int index = mpp[mat[j][i]];
                lastElement = max(index,lastElement);
            }
            result = min(result,lastElement);
        }
        return result;
    }
};

/*
Time complexity: O(m*n) + O(m*n) = O(m*n)
Space complexity: O(m*n)
*/

int main()
{
    Solution s;
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4},{2,3}};
    cout<<s.firstCompleteIndex(arr,mat)<<endl;
    return 0;
}