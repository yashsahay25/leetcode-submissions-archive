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
    int solve(TreeNode* node, int& maxLen){
        if(!node) return 0;

        int lh = solve(node->left, maxLen);
        int rh = solve(node->right, maxLen);

        maxLen = max(maxLen, lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // maxLen via a node = left + right
        int maxLen = 0;
        solve(root, maxLen);
        return maxLen;
    }
};