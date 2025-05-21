#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool zero_col = false;
        bool zero_row = false;

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                zero_col = true;
                break;
            }
        }

        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                zero_row = true;
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (zero_col) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

        if (zero_row) {
            for (int i = 0; i < m; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};

/*
Time Complexity: O(m*n)
Space Complexity: O(1)
*/

/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n,-1);
        vector<int> col(m,-1);

        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(row[i]==1||col[j]==1)
                {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};

Time Complexity: O(m*n)
Space Complexity: O(m+n)

*/


int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}