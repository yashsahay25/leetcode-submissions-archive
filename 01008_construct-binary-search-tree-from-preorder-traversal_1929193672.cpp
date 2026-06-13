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
    int nextGreaterIndex(int rootVal, vector<int>& preorder, int l, int r){
        for(int i=l;i<=r;i++){
            if(preorder[i] > rootVal) return i;
        }
        return -1;
    }
    TreeNode* construct(vector<int>& preorder, int l, int r){
        if(l>r) return NULL;
        
        // first value will be root node
        TreeNode* root = new TreeNode(preorder[l]);

        // find index of first element which is greater than root
        int idx = nextGreaterIndex(root->val, preorder, l+1, r);

        // if idx not found, it means no left, only right part exists    
        if (idx == -1)
            idx = r + 1;
        
        // recursively construct the BST
        root->left = construct(preorder, l+1, idx-1);
        root->right = construct(preorder, idx, r);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size()-1);
    }
};