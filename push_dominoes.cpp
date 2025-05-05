#include <bits/stdc++.h>
using namespace std;

/*
There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.



Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."


Constraints:

n == dominoes.length
1 <= n <= 10^5
dominoes[i] is either 'L', 'R', or '.'.
*/

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int l = 0;
        int r = 0;
        int n = dominoes.size();
        string ans(dominoes.begin(), dominoes.end());
        while (r < n)
        {
            if (dominoes[r] == 'R')
            {
                int ind = r + 1;
                int cnt = 0;
                while (ind < n && dominoes[ind] == '.')
                {
                    cnt++;
                    ind++;
                }

                if (ind == n)
                {
                    for (int i = r + 1; i < n; i++)
                    {
                        ans[i] = 'R';
                    }
                    r = ind;
                }
                else if (dominoes[ind] == 'R')
                {
                    for (int i = r + 1; i < ind; i++)
                    {
                        ans[i] = 'R';
                    }
                    r = ind - 1;
                }
                else if (dominoes[ind] == 'L')
                {
                    if (cnt % 2 == 0)
                    {
                        for (int i = r + 1; i < r + 1 + cnt / 2; i++)
                        {
                            ans[i] = 'R';
                        }
                        for (int i = r + 1 + cnt / 2; i < ind; i++)
                        {
                            ans[i] = 'L';
                        }
                    }
                    else
                    {
                        for (int i = r + 1; i < r + 1 + cnt / 2; i++)
                        {
                            ans[i] = 'R';
                        }
                        for (int i = r + 1 + cnt / 2 + 1; i < ind; i++)
                        {
                            ans[i] = 'L';
                        }
                    }
                    r = ind;
                }
            }
            r++;
        }
        r = n - 1;
        while (r >= 0)
        {
            if (dominoes[r] == 'L')
            {
                int ind = r - 1;
                int cnt = 0;
                while (ind >= 0 && dominoes[ind] == '.')
                {
                    cnt++;
                    ind--;
                }

                if (ind < 0)
                {
                    for (int i = r - 1; i >= 0; i--)
                    {
                        ans[i] = 'L';
                    }
                    r = -1;
                }
                else if (dominoes[ind] == 'L')
                {
                    for (int i = r - 1; i > ind; i--)
                    {
                        ans[i] = 'L';
                    }
                    r = ind + 1;
                }
            }
            r--;
        }

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is the length of the dominoes string.
*/

int main()
{
    Solution sol;
    string dominoes = ".L.R...LR..L..";
    cout << sol.pushDominoes(dominoes) << endl; // Output: "LL.RR.LLRRLL.."
    return 0;
}