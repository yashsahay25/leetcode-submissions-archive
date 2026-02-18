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
        if (root == NULL)   return root;

        // here don't need to traverse both sides each time, unlike binary tree

        // if p & q < curr, we travel left
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // if p & q > curr, we travel right
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // if neither condition is true, it means we are the point where the path
        // path from root to these nodes splits --> it will be answer 
        // (same logic as brute force path)
        return root;
    }
};