#include <bits/stdc++.h>
using namespace std;

/*
We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.



Example 1:


Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:


Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
Example 3:


Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]


Constraints:

The number of nodes in the original tree is in the range [1, 1000].
1 <= Node.val <= 10^9

*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class Solution
{
private:
    void makeTree(TreeNode *node, string &traversal, int level, int &index, int n)
    {
        while (index < n)
        {
            int curlevel = 0;

            while (index < n && traversal[index] == '-')
            {
                curlevel++;
                index++;
            }

            if (curlevel <= level)
            {
                index -= curlevel;
                return;
            }

            int val = 0;
            while (index < n && isdigit(traversal[index]))
            {
                val = val * 10 + (traversal[index] - '0');
                index++;
            }
            TreeNode *newNode = new TreeNode(val);
            if (node->left == nullptr)
            {
                node->left = newNode;
            }
            else
            {
                node->right = newNode;
            }
            makeTree(newNode, traversal, curlevel, index, n);
        }
    }

public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        if (traversal.empty())
            return nullptr;

        int rootVal = 0;
        int index = 0;
        while (index < traversal.length() && isdigit(traversal[index]))
        {
            rootVal = rootVal * 10 + (traversal[index] - '0');
            index++;
        }

        TreeNode *root = new TreeNode(rootVal);
        makeTree(root, traversal, 0, index, traversal.length());
        return root;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

// main function
void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    Solution sol;
    TreeNode *root = sol.recoverFromPreorder("1-2--3--4-5--6--7");
    print(root);
    return 0;
}