#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 2:


Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 3:


Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All the values of the tree are unique.

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
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty())
        {
            int s = q.size();
            vector<int> index(s,0);
            iota(index.begin(),index.end(),0);
            vector<int> arr;
            for(int i =0;i<s;i++)
            {
                auto it = q.front();
                q.pop();
                arr.push_back(it->val);
                if(it->left)
                q.push(it->left);
                if(it->right)
                q.push(it->right);
            }
            sort(index.begin(),index.end(),[&](int i,int j){
                return arr[i]<arr[j];
            });

            for(int i =0;i<s;)
            {
                int j = index[i];
                if(j!=i)
                {
                    ans++;
                    swap(index[i],index[j]);
                }else
                {
                    i++;
                }
            }
        }
        return ans;
    }
};
//Time Complexity : O(NlogN)
//Space Complexity : O(N)


// class Solution {
// public:
//     int minimumOperations(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         int ans = 0;
//         while(!q.empty())
//         {
//             int size = q.size();
//             vector<int> nums;
//             for(int i =0;i<size;i++)
//             {
//                 auto it = q.front();
//                 q.pop();

//                 nums.push_back(it->val);
//                 if(it->left)
//                 q.push(it->left);
//                 if(it->right)
//                 q.push(it->right);
//             }
//             if(nums.size()==2)
//             {
//                 if(nums[0]>nums[1])
//                 ans = ans +1;
//             }else
//             {
//                 unordered_map<int,int> mpp;
//                 for(int i =0;i<nums.size();i++)
//                 {
//                     mpp[nums[i]]=i;
//                 }
//                 sort(nums.begin(),nums.end());
//                 vector<bool> vis(nums.size(),false);

//                 for(int i =0;i<nums.size();i++)
//                 {
//                     if(vis[i] || mpp[nums[i]]==i)
//                     continue;

//                     int j=i;
//                     int cycle = 0;
//                     while(!vis[j])
//                     {
//                         vis[j]=true;

//                         j = mpp[nums[j]];
//                         cycle++;
//                     }
//                     if(cycle>0)
//                     ans = ans + (cycle-1);
//                 }
//             }
//         }
//         return ans;
//     }
// };
//Time Complexity : O(NlogN)
//Space Complexity : O(N)

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(5);
    root->left->left->right = new TreeNode(9);
    root->right->left->right = new TreeNode(10);
    Solution s;
    cout<<s.minimumOperations(root);
}