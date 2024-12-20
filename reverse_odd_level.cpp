/*
Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
Example 2:


Input: root = [7,13,11]
Output: [7,11,13]
Explanation: 
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
Example 3:

Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation: 
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.
 

Constraints:

The number of nodes in the tree is in the range [1, 214].
0 <= Node.val <= 105
root is a perfect binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
void reverseLevel(TreeNode* leftC,TreeNode* rightC, int level)
{
    if(leftC==nullptr||rightC==nullptr)
    return;

    if(level%2==0)
    swap(leftC->val,rightC->val);

    reverseLevel(leftC->left,rightC->right,level+1);
    reverseLevel(leftC->right,rightC->left,level+1);
}
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseLevel(root->left,root->right,0);
        return root;
    }
};

void print(TreeNode* root)
{
    if(root==nullptr)
    return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);


}
// Time Complexity : O(N)
// Space Complexity : O(logN)

 /*
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<TreeNode*> curNode;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();
                if(level%2!=0)
                {
                    curNode.push_back(it);
                }
                if(it->left)
                q.push(it->left);
                if(it->right)
                q.push(it->right);
            }

            if(level%2!=0)
            {
                for(int i = 0;i<curNode.size()/2;i++)
                {
                    swap(curNode[i]->val,curNode[curNode.size()-i-1]->val);
                }
            }
            level++;
            curNode.clear();
        }
        return root;
    }
};
Time complexity : O(N)
Space Complexity : O(N)
*/

//Brute Solution
// class Solution {
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = 0;
//         while (!q.empty()) {
//             vector<int> nodes;
//             int n = q.size();
//             queue<TreeNode*> qs;
//             for (int i = 0; i < n; i++) {
//                 auto it = q.front();
//                 q.pop();
//                 qs.push(it);
//                 if (it->left) {
//                     nodes.push_back(it->left->val);
//                     q.push(it->left);
//                 }
//                 if (it->right) {
//                     nodes.push_back(it->right->val);
//                     q.push(it->right);
//                 }
//             }
//             if (level % 2 == 0) {
//                 int ns = qs.size();
//                 int k = 0;
//                 reverse(nodes.begin(), nodes.end());
//                 for (int i = 0; i < ns; i++) {
//                     auto it = qs.front();
//                     qs.pop();
//                     if (it->left) {
//                         it->left->val = nodes[k++];
//                     }
//                     if (it->right) {
//                         it->right->val = nodes[k++];
//                     }
//                 }
//             }
//             level++;
//         }
//         return root;
//     }
// };

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);
    print(root);
    cout<<endl;
    Solution s;
    TreeNode* res = s.reverseOddLevels(root);
    print(res);

    return 0;
}