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
    bool validate(TreeNode* root, TreeNode*& prev) {
        if (!root)  return true;    // empty sutree is BST (leaf node)
        if (!validate(root->left, prev)) // first check in left subtree
            return false;
        if (prev && prev->val >= root->val) // check current node
            return false;
        prev = root;    // update prev
        return validate(root->right, prev); // check in right subtree
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;       // inorder predecessor
        return validate(root, prev); // inorder traversal
    }
};