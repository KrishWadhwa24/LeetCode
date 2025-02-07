#include <bits/stdc++.h>
using namespace std;

/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task:
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100
*/

class Solution
{
public:
    void popping(int el, stack<int> &s)
    {
        if (s.empty() || s.top() <= el)
        {
            s.push(el);
            return;
        }

        int node = s.top();
        s.pop();
        popping(el, s);
        s.push(node);
    }

    void emptyStack(stack<int> &s)
    {
        if (s.empty() || s.size() == 1)
            return;

        int el = s.top();
        s.pop();
        emptyStack(s);
        popping(el, s);
    }

    void sorting(stack<int> &s)
    {
        emptyStack(s);
    }
};
/*
Time Complexity: O(N*N)
Space Complexity: O(N)
*/

int main()
{
    stack<int> s;
    s.push(11);
    s.push(1);
    s.push(2);
    s.push(32);
    s.push(3);
    s.push(41);

    Solution sol;
    sol.sorting(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
