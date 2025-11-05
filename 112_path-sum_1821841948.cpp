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
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return false;
        
        // if we are leaf node, then is the remaining targetSum equal to node's value?
        if(!root->left && !root->right){
            if(target==root->val) return true;
        }
        
        // Otherwise, check the left and right subtrees with the reduced target
        int remaining = target - root->val;

        bool hasLeftSum = hasPathSum(root->left, remaining);
        bool hasRightSum = hasPathSum(root->right, remaining);
        
        return hasLeftSum || hasRightSum;
    }
};