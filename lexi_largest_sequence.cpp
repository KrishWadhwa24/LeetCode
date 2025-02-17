#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.



Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]


Constraints:

1 <= n <= 20
*/

class Solution
{
private:
    bool isSafe(vector<int> &answer, int num, int j, int n)
    {
        if (num == 1)
        {
            return (answer[j] == 0);
        }
        if (j + num < 2 * n - 1 && answer[j] == 0 && answer[j + num] == 0)
        {
            return true;
        }
        return false;
    }
    bool backtrack(vector<int> &answer, vector<int> &freq, int n, int cnt, int j)
    {
        if (cnt == 0)
        {
            return true;
        }
        if (answer[j] != 0)
        {
            if (backtrack(answer, freq, n, cnt, j + 1))
                return true;
        }
        if (j >= answer.size())
        {
            return false;
        }
        for (int num = n; num >= 1; num--)
        {
            if (!freq[num] && isSafe(answer, num, j, n))
            {
                answer[j] = num;
                if (num > 1)
                    answer[j + num] = num;
                freq[num] = 1;
                if (backtrack(answer, freq, n, cnt - 1, j + 1))
                {
                    return true;
                }
                answer[j] = 0;
                if (num > 1)
                    answer[j + num] = 0;
                freq[num] = 0;
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> answer(2 * n - 1, 0);
        vector<int> freq(n + 1, 0);
        backtrack(answer, freq, n, n, 0);
        return answer;
    }
};

/*
Time Complexity: O(N!)
Space Complexity: O(N)
*/

int main()
{
    Solution s;
    vector<int> ans = s.constructDistancedSequence(3);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}