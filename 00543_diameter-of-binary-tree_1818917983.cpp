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
    // diameter = longest path from any node to any node
    // so we can calc this path length for each node & take max
    // this path length = left + right height

    int findHeight(TreeNode* root, int& diameter) {
        if (!root)  return 0;

        // find height as usual
        int lh = findHeight(root->left, diameter);
        int rh = findHeight(root->right, diameter);
        
        // d for any node = lh + rh, update maxD so far also
        diameter = max(diameter, lh + rh);

        // usual return of find height of binary tree
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // declare a variable here or global
        int diameter = 0;
        findHeight(root, diameter);
        return diameter;
    }
};