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
    int dfs(TreeNode *root,int curr_sum)
    {
        if(!root)   return 0;
        int sumTillnow = curr_sum*10 + root->val;
        if(!root->left and !root->right)
            return sumTillnow;
        
        return dfs(root->left,sumTillnow) + dfs(root->right,sumTillnow);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};