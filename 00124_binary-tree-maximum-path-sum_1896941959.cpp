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
    int dfs(TreeNode* root, int& pathSum){
        if(!root) return 0;

        int leftSum=max(0, dfs(root->left, pathSum));
        int rightSum=max(0, dfs(root->right, pathSum));

        pathSum = max(pathSum, root->val+leftSum+rightSum);

        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int pathSum=INT_MIN;
        dfs(root,pathSum);
        return pathSum;
    }
};