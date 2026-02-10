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
    TreeNode* build(vector<int>& pre, int preStart, int preEnd, vector<int>& in,
                    int inStart, int inEnd, unordered_map<int, int>& inHash) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        int rootVal = pre[preStart]; // root value will starting of preorder
        TreeNode* root = new TreeNode(rootVal); // create root node

        int idx = inHash[rootVal]; // root index in inorder

        int numsLeft = idx - inStart;
        // numbers on left side which will form the left subtree
        // so we consider only those below

        root->left = build(pre, preStart + 1, preStart + numsLeft, 
                        in, inStart, idx - 1, inHash);
        root->right = build(pre, preStart + numsLeft + 1, preEnd, 
                        in, idx + 1, inEnd, inHash);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inHash; // <inorder value, index>
        for (int i = 0; i < inorder.size(); i++) {
            inHash[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inHash);
    }
};