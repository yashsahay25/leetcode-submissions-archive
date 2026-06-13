/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if node is null, return null
        if(root == NULL) return NULL;

        // if either of p or q matches current node, return that node
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // these LCA can be either null or return node (if value found)
        // so total 4 combinations
        // if both null return null
        // if both exists, that's our answer
        // if either is null, return the other one

        if(left != NULL && right != NULL) return root;
        if(left == NULL && right == NULL) return NULL;
        if(left == NULL) return right;
        else return left;
        
    }
};