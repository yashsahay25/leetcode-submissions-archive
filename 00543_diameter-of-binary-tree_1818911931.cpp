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
    // diameter = longest path from any node to any node
    // so we can calc this path length for each node & take max
    // this path length = left + right height
    int maxH=0;
    int findHeight(TreeNode* root){
        if(!root) return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int lht = findHeight(root->left);
        int rht = findHeight(root->right);

        maxH = max(maxH, lht+rht); 
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxH;
    }
};