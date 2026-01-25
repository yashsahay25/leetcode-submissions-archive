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
class Solution {
public:
    int calcHeight(TreeNode* root) {
        if (!root)  return 0;
        int lh = calcHeight(root->left);
        int rh = calcHeight(root->right);

        // condition for unbalanced
        // 1. if any child subtree is unbalanced, we return -1 directly
        // 2. or we check for current node, the height difference
        if (lh == -1 || rh == -1)   return -1;
        if (abs(lh - rh) > 1)   return -1;

        // if balanced, we simply return height
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        // we use the same dfs method which calculates
        // height, & make it return -1 incase of unbalanced
        return calcHeight(root) != -1;
    }
};