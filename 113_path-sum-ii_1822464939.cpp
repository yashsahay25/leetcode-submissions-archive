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
    void solve(TreeNode* node, int target, vector<int> path, vector<vector<int>>& res){
        if(!node) return;

        path.push_back(node->val);

        if(!node->left && !node->right){
            if(target==node->val){
                res.push_back(path);
            }
        }

        solve(node->left, target-node->val, path, res);
        solve(node->right, target-node->val, path, res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        solve(root, targetSum, path, result);
        return result;
    }
};