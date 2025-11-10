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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both null, they're identical
        if(!p && !q) return true;

        // if either is null or value isn't same
        if(!p || !q || p->val != q->val) return false;

        // recursively check further
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};