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
    void inorder(TreeNode* root,int &sum)
    {
        if(root->right) 
            inorder(root->right,sum);
        sum+=root->val;
        root->val = sum;
        if(root->left)  
            inorder(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)   return NULL;
        int sum=0;
        inorder(root,sum);
        return root;
    }
};