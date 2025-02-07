#include<bits/stdc++.h>
using namespace std;

/*
You are given a stack St. You have to reverse the stack using recursion.

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.
Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Explanation:
Input stack after reversing will look like the stack in the output.
Your Task:

You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and reverses the given stack.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= size of the stack <= 104
-109 <= Each element of the stack <= 109
Sum of N over all test cases doesn't exceeds 106
Array may contain duplicate elements. 
*/

class Solution{
    private:
    void popping(int el,stack<int>& st)
    {
        if(st.empty())
        {
            st.push(el);
            return;
        }
        
        int node = st.top();
        st.pop();
        
        popping(el,st);
        st.push(node);
    }
public:
    void Reverse(stack<int> &St){
        
        if(St.empty()||St.size()==1)
        return;
        int element = St.top();
        St.pop();
        Reverse(St);
        popping(element,St);
    }
};
/*
Time Complexity: O(N^2)
Space Complexity: O(1)
*/

int main()
{
    Solution s;
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);
    s.Reverse(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    stack<int> st1;
    st1.push(4);
    st1.push(3);
    st1.push(9);
    st1.push(6);
    s.Reverse(st1);
    while(!st1.empty())
    {
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<endl;
    return 0;
}