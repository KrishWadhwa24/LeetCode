#include <bits/stdc++.h>
using namespace std;

/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.



Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]


Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &postOrder, int postStart, int postEnd,
                    unordered_map<int, int> &mpp)
    {
        if (preStart > preEnd || postStart > postEnd)
            return NULL;

        if (preStart == preEnd)
            return new TreeNode(preorder[preStart]);

        int leftChild = preorder[preStart + 1];
        int numsLeft = mpp[leftChild] - postStart + 1;

        TreeNode *root = new TreeNode(preorder[preStart]);

        root->left = build(preorder, preStart + 1, preStart + numsLeft,
                           postOrder, postStart, mpp[leftChild], mpp);

        root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                            postOrder, mpp[leftChild] + 1, postEnd - 1, mpp);

        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &preorder,
                                   vector<int> &postorder)
    {
        int n = preorder.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[postorder[i]] = i;
        }
        return build(preorder, 0, n - 1, postorder, 0, n - 1, mpp);
    }

    void printTree(TreeNode *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
};
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

int main()
{
    Solution s;
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    TreeNode *root = s.constructFromPrePost(preorder, postorder);
    s.printTree(root);
    return 0;
}