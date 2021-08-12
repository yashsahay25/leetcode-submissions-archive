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
    int res=0;
    int dfs(TreeNode *root)
    {
        if(!root)   return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int l2=0,r2=0;
        if(root->left and root->val == root->left->val)
            l2=l+1;    //add one more edge corres. to root & lchild
        if(root->right and root->val == root->right->val)
            r2=r+1;    //add one more edge corres. to root & rchild
        //reason for l+r is that
        //path can bend around any node like form left to right,
        //so we need to include left + right both
        res = max(res,l2+r2);
        
        //path should not have any branched nodes
        return max(l2,r2);
    }
    int longestUnivaluePath(TreeNode* root) 
    {
        dfs(root);
        return res; //global variable
    }
};