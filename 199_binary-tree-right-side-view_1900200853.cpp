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
    void dfs(TreeNode* root, int level, vector<int>& result){
        if(!root) return;

        // Intuitive Step
        if(level==result.size()) result.push_back(root->val);

        // first go to right node, then left
        dfs(root->right, level+1, result);
        dfs(root->left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        dfs(root,0, result);
        return result;
    }
};