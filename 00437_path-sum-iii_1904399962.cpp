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
    void findPathSum(TreeNode* root, long long target, int& count) {
        if (!root)  return;

        if (root->val == target) {
            count++; // count THIS path
            // DO NOT return as path can be extended
        }

        findPathSum(root->left, target - root->val, count);
        findPathSum(root->right, target - root->val, count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)  return 0;

        int count = 0;
        findPathSum(root, targetSum, count);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};