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
    TreeNode* construct(vector<int>& preorder, int& i, int upperBound) {
        if (i == preorder.size() || preorder[i] > upperBound)
            return NULL;

        // first node will be root element
        TreeNode* root = new TreeNode(preorder[i]);
        i++; // move to next element

        root->left = construct(preorder, i, root->val); // left < root
        root->right = construct(preorder, i, upperBound);    // right < upper_bound of root

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;  // start from 1st index
        return construct(preorder, i, INT_MAX); // upper_bound = +INT_MAX
    }
};