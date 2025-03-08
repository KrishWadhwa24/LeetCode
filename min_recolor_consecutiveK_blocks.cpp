#include <bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.



Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW".
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
Example 2:

Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.


Constraints:

n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n
*/

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int l = 0;
        int r = 0;
        int white = 0;
        int answer = INT_MAX;
        while (r < blocks.length())
        {
            if (blocks[r] == 'W')
                white++;

            if (r - l + 1 == k)
            {
                answer = min(answer, white);
                if (blocks[l] == 'W')
                {
                    white--;
                }
                l++;
            }
            r++;
        }
        return answer;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

int main()
{
    Solution s;
    string blocks = "WBBWWBBWBW";
    int k = 7;
    cout << s.minimumRecolors(blocks, k) << endl;
    return 0;
}