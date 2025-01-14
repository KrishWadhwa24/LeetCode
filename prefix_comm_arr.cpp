#include<bits/stdc++.h>
using namespace std;

/*
You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 

Example 1:

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
Example 2:

Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
 

Constraints:

1 <= A.length == B.length == n <= 50
1 <= A[i], B[i] <= n
It is guaranteed that A and B are both a permutation of n integers.

*/


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> freq(n+1, 0), res(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            
            freq[A[i]]++;
            if (freq[A[i]] == 2) cnt++;

            freq[B[i]]++;
            if (freq[B[i]] == 2) cnt++;

            res[i] = cnt;
        }
        return res;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n,0);
        int cnt = A.size();
        unordered_map<int,int> mpp;
        for(int i =n-1;i>=0;i--)
        {
            res[i] = cnt;
            if(mpp.find(A[i])==mpp.end())
            {
                mpp[A[i]] = i;
                cnt--;
            }

            if(mpp.find(B[i])==mpp.end())
            {
                mpp[B[i]] = i;
                cnt--;
            }
        }
        return res;
    }
};
Time Complexity: O(n)
Space Complexity: O(n)

*/



int main() {
    Solution s;
    vector<int> A = {1,3,2,4}, B = {3,1,2,4};
    vector<int> res = s.findThePrefixCommonArray(A, B);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}