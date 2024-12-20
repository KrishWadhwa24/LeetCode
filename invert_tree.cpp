#include <bits/stdc++.h>
using namespace std;
/*

Given the root of a binary tree, invert the tree, and return its root.



Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
// Time Complexity : O(N)
// Space Complexity : O(logN)

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root==nullptr)
//         return root;
//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty())
//         {
//             TreeNode* it = q.front();
//             q.pop();

//             swap(it->left,it->right);

//             if(it->left)
//             q.push(it->left);
//             if(it->right)
//             q.push(it->right);
//         }
//         return root;
//     }
// };
// Time Complexity : O(N)
// Space Complexity : O(N)

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    printTree(root);
    cout<<"\n";
    Solution s;
    TreeNode *res = s.invertTree(root);
    printTree(res);
    return 0;
}