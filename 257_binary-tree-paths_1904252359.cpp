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
    void dfs(TreeNode* root, vector<string>& paths, string value){
        if(!root->left && !root->right) {
            paths.push_back(value);
            return;
        }
        if(root->left)
            dfs(root->left, paths, value + "->" + to_string(root->left->val));
        if(root->right)
            dfs(root->right, paths, value + "->" + to_string(root->right->val));

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(!root) return paths;

        dfs(root, paths, to_string(root->val));
        return paths;
    }
};