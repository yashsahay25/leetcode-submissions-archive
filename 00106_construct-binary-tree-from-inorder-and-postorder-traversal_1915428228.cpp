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
    TreeNode* build(vector<int>& post, int postStart, int postEnd, vector<int>& in,
                    int inStart, int inEnd, unordered_map<int, int>& inHash) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        int rootVal = post[postEnd]; // root value will ending of postorder
        TreeNode* root = new TreeNode(rootVal); // create root node

        int idx = inHash[rootVal]; // root index in inorder

        int numsLeft = idx - inStart;
        // numbers on left side which will form the left subtree
        // so we consider only those below

        root->left = build(post, postStart, postStart + numsLeft - 1, 
                        in, inStart, idx - 1, inHash);
        root->right = build(post, postStart + numsLeft, postEnd - 1, 
                        in, idx + 1, inEnd, inHash);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inHash; // <inorder value, index>
        for (int i = 0; i < inorder.size(); i++) {
            inHash[inorder[i]] = i;
        }
        return build(postorder, 0, postorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inHash);
    }
};