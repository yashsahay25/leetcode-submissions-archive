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
    void dfs(TreeNode* root, int& count, int& res, int k) {
        if (!root) return;
        // left, root, right
        dfs(root->left, count, res, k);
        if (++count == k) {
            res = root->val;
            return;
        }
        dfs(root->right, count, res, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res;
        int count = 0;
        dfs(root, count, res, k);
        return res;
    }
};